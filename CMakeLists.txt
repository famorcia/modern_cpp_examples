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
project (cpp11_examples)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wextra -Wall -Werror")

add_subdirectory(MapAndSet)

add_subdirectory(01_cplusplus)
add_subdirectory(02_auto)
add_subdirectory(03_range_for)
add_subdirectory(04_right_angle_brackets)
add_subdirectory(05_control_of_defaults_default_and_delete)
add_subdirectory(06_control_of_defaults_move_and_copy)
add_subdirectory(07_enum_class)
add_subdirectory(08_constexpr)

add_subdirectory(corso)


