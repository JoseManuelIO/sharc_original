# --- Archivo de Toolchain para PULP (v4 - Final) ---

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR riscv)

set(TOOLCHAIN_DIR /home/jmini/PULP/pulp-riscv-gnu-toolchain/install)

set(CMAKE_C_COMPILER   ${TOOLCHAIN_DIR}/bin/riscv64-unknown-elf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/riscv64-unknown-elf-g++)

set(CMAKE_EXE_LINKER_FLAGS "-T /home/jmini/PULP/pulp-sdk/rtos/pulpos/pulp/kernel/chips/pulp/link.ld -nostdlib" CACHE STRING "Linker Flags")

# --- LA CORRECIÓN DEFINITIVA ---
# Ahora le decimos a CMake que puede buscar tanto en nuestro toolchain
# como en las carpetas estándar del sistema anfitrión.
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR} /usr /lib/x86_64-linux-gnu)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Cambiamos a BOTH para que busque en ambos sitios: primero en el toolchain, luego en el sistema.
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)
include_directories(/home/jmini/sharc_original/libmpc/include)
