package hellope_gencpp

import cpp "../gencpp"
import "core:fmt"

main :: proc() {
	ctx : cpp.Context
	cpp.init(& ctx)

	src_hellope : cpp.Builder  := cpp.builder_open("gen/hellope.c")
	hellope_var : cpp.Code_Var := cpp.parse_variable(
		"char const* hellope_gencpp_str" = "HELLOPE GENCPP ODIN !"
	)
	cpp.builder_print(& src_hellope, hellope_var)
	cpp.builder_write(& src_hellope)

	body := cpp.parse_file("gen/hellope.c")
	iter := cpp.body_iter(body)
	for code := iter.peek(); code != cpp.body_iter_end(iter); code = iter.next() {
		switch(code.type) {
			case .Variable:
				var := cast(Code_Var) code
				fmt.tprintf("%v", cpp.var_to_string(var.value))
		}
	}

	cpp.deinit(& ctx)
}
