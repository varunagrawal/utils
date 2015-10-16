from distutils.core import setup, Extension

module1 = Extension('varun', sources = ['varun.c'])

setup(name = 'PackageName', version = '1.0', description = 'This is Varun\'s custom module', ext_modules = [module1])

