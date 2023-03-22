#  cpp11 examples
#  Copyright (C) 2022  Fabrizio Morciano
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.

#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License along
#  with this program; if not, write to the Free Software Foundation, Inc.,
#  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wextra -Wall -Werror")


add_subdirectory(01_coroutines)
add_subdirectory(02_concepts)
add_subdirectory(03_designated_initializers)
add_subdirectory(04_template_lambda)
add_subdirectory(05_range_based_for_loop_with_initializer)
add_subdirectory(06_likely_unlikely)
add_subdirectory(07_constexpr_virtual_function)
add_subdirectory(08_consteval_constinit)
add_subdirectory(09_synch_out_buffer)
add_subdirectory(10_span)




