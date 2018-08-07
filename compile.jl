ENV["COMPILE_STATIC"] = true
include(joinpath(Pkg.dir("PackageCompiler"), "juliac.jl"))

args = ["-vcasj", "--cc-flags=-Wl,-rpath,\$ORIGIN", "--compile=all", "foo_AOT.jl"]

print_with_color(:cyan, "juliac.jl $(join(args, " "))\n")
julia_main(args)

includePath = joinpath(JULIA_HOME, Base.INCLUDEDIR, "julia")
command = `g++ -shared -o foo_driver.so ../driver/foo_driver.cpp -std=c++11 -I$includePath -DJULIA_ENABLE_THREADING=1 -fPIC -Wl,--export-dynamic -m64 foo_AOT.so '-Wl,-rpath,$ORIGIN'`
print_with_color(:cyan, command, "\n")
run(command)

command = `g++ -o app ../app/app.cpp -std=c++11 -fPIC -m64 foo_driver.so '-Wl,-rpath,$ORIGIN' -fuse-ld=gold`
print_with_color(:cyan, command, "\n")
run(command)

command = `./app`
print_with_color(:cyan, command, "\n")
run(command)

