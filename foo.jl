module Foo

struct Data
  name::String
  values::Vector{Float64}
end

function doSomething(data::Vector{Data}, io=STDOUT)
  for d in data
    println(io, uppercase(d.name), " ", BLAS.asum(length(d.values), d.values, 1))
  end
end
  
function bar(data::Vector{Data})
  isempty(data) && return 1
  doSomething(data)
  return 0
end

function baz(data::Vector{Data}, logPath::String)
  isempty(data) && return 1
  open(logPath, "w") do io
    doSomething(data, io)
  end
  return 0
end

end
