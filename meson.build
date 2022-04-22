# Meson is better than CMake, though neither are any good.
#
# version var should be provided HERE, but meson requires first statement to be project,
# that's why version isn't provided to project call, so you don't have to change two values.

project('Lain',
        'c', 'cpp',
        default_options: [
          'optimization=3',
          'warning_level=3',
          'c_std=c99',
          'cpp_std=c++14',
          'c_winlibs=[]',
          'cpp_winlibs=[]',
        ],
        license : 'GPL-3.0-only',
)

# Large.Small for tags/releases, with patches its 'Large.Small.Patch'.
# Iterate Patch every few 'important' commits, or for hotfixes;
# Iterate Small on update release or biweekly; and
# Iterate Large when Small is too big. Too big being, somewhere around twenty.
version = '0.0.1'

includedir = ['include', 'dependencies']

cppargs = ['-DVERSION="' + version + '"', '-DTESTING'] # c & cpp

cargs   = [] # c
cxxargs = [] # cpp

# I should make a pull request to meson with an easier raw ram linkage.
cc = meson.get_compiler('c')
dep = [cc.find_library('m', required : true), cc.find_library('pthread', required : true), dependency('glfw3'), dependency('openal'), dependency('opengl')]

executable('Lain',
           'src/glad.c', 'src/parse.c', 'src/main.cpp', 'src/game.cpp', 'src/menu.cpp', 'src/gameobject.cpp', 'src/scene.cpp',
           c_args : [cargs, cppargs],
           cpp_args : [cxxargs, cppargs],
           include_directories : includedir,
           # this is the primary reason I use this over CMake, less pain and weirdness with dependencies.
           dependencies : dep)
