using Documenter

makedocs(
    format = :html,
    sitename = "AOTDemo.jl",
    pages = [
        "index.md",
    ]
)

deploydocs(
    repo = "github.com/tangentworks/AOTDemo.jl.git",
    target = "build",
    julia  = "0.6",
    deps = nothing,
    make = nothing,
    osname = "linux"
)

