cmake_minimum_required(VERSION 3.15)
project(libftprintf)

set(CMAKE_C_STANDARD 90)

set(SOURCE_LIBFTPRINTF
        src/ft_abs.c
        src/ft_add_dig_to_int.c
        src/ft_add_specials.c
        src/ft_b.c
        src/ft_buff_finded_percent.c
        src/ft_buff_free.c
        src/ft_buff_no_percent.c
        src/ft_buff_print_free.c
        src/ft_buff_print_n_len.c
        src/ft_buff_treated_percent.c
        src/ft_bzero_buf_n_set_pointers.c
        src/ft_c.c
        src/ft_choose_func.c
        src/ft_count_float.c
        src/ft_di.c
        src/ft_dollar_arg.c
        src/ft_dollar_treat.c
        src/ft_error_exit.c
        src/ft_exeption_treat.c
        src/ft_f.c
        src/ft_final_print_n_free_rt_len.c
        src/ft_find_digit.c
        src/ft_find_in_def.c
        src/ft_get_divisional.c
        src/ft_get_integer.c
        src/ft_i64toa_base.c
        src/ft_integer_to_str.c
        src/ft_isbigger.c
        src/ft_num_to_str.c
        src/ft_o.c
        src/ft_p.c
        src/ft_parse_flags.c
        src/ft_parse_spec.c
        src/ft_parsing.c
        src/ft_percent_treat.c
        src/ft_precision_treat.c
        src/ft_printf.c
        src/ft_round_float.c
        src/ft_s.c
        src/ft_strcpy_dptp.c
        src/ft_strpcpy.c
        src/ft_to_pow.c
        src/ft_u.c
        src/ft_u64toa_base.c
        src/ft_width_n_precision.c
        src/ft_width_treat.c
        src/ft_x.c)

include_directories(includes)
include_directories(libft/inc)

#add_executable(libftprintf)
add_library(libftprintf STATIC ${SOURCE_LIBFTPRINTF})

add_subdirectory(libft)
target_link_libraries(libftprintf libft)