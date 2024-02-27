
add_rules("mode.debug", "mode.release")
add_requires("gtest 1.12.*")

set_languages("cxx20")
set_optimize("fastest")

target("pysl")
    set_kind("shared")
    add_files("src/*.cpp")
    add_cxflags("$(shell pixi run python -m pybind11 --includes)")
    add_packages("gtest")
    after_build(
        function(target)
            local targetfile = target:targetfile()
            local src =  os.getenv("PWD") .. "/src" 
            local new_file = path.join(src, path.filename(targetfile):sub(4))
            os.cp(targetfile,  new_file)
        end
    )
    

-- target("test")
--     set_kind("binary")
--     add_files("tests/*.cpp")
--     -- add_deps("pysl")
--     -- add_cxflags("$(shell pixi run python -m pybind11 --includes)")
--     add_packages("gtest")
--     set_group("test")
