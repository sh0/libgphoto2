#
# libgphoto2
#

function (set_compiler_settings TARGET)
    target_compile_options(
        ${TARGET} PRIVATE
        $<$<C_COMPILER_ID:MSVC>:/MP /W4>
        $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -Wshadow -Wno-unused-parameter -Wno-sign-compare -Werror-implicit-function-declaration>
        $<$<C_COMPILER_ID:Clang>:-Wall -Wextra -Wshadow-all -Wno-unused-parameter -Wno-sign-compare>
    )
endfunction ()
