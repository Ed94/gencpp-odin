package hellope_gencpp

import cpp "../gencpp"
import "core:fmt"

main :: proc() {
	ctx : cpp.Context
	cpp.init(& ctx)

	src_hellope := cpp.builder_open("gen/hellope.c")
	hellope_var := cpp.parse_variable(
		"char const* hellope_gencpp_str" = "HELLOPE GENCPP ODIN !"
	)
	cpp.builder_print(& src_hellope, hellope_var)
	cpp.builder_write(& src_hellope)

	body := cpp.parse_file("gen/hellope.c")
	for code := cpp.begin(body); code != cpp.end(body); code = cpp.next(body, code) {
		switch(code.type) {
			case .Variable:
				var := cast(cpp.Code_Var) code
				fmt.tprintf("%v", cpp.to_string(var.value))
		}
	}

	cpp.deinit(& ctx)
}
