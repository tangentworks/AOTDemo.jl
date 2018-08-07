include("foo.jl")

using Foo: Data


struct CData
  name::Ptr{Cwchar_t}
  valuesPtr::Ptr{Cdouble}
  valuesLen::Csize_t
end

function Base.convert(::Type{Data}, s::CData)
  values = unsafe_wrap(Array, s.valuesPtr, s.valuesLen)
  name = wchartostring(s.name)
  Data(name, values)
end

function wchartostring(p::Ptr{Cwchar_t}; maxlen = 65536)
  len = 0
  while unsafe_load(p, len + 1) != 0 && len < maxlen; len += 1; end
  transcode(String, unsafe_wrap(Array{Cwchar_t,1}, p, len))
end


# These functions just convert C objects to Julia objects and call corresponding Julia functions.

Base.@ccallable function jl_FOO_bar(dataPtr::Ptr{CData}, dataLen::Csize_t)::Cint
  data = Vector{Data}(unsafe_wrap(Array, dataPtr, dataLen))
  Foo.bar(data)
end

Base.@ccallable function jl_FOO_baz(dataPtr::Ptr{CData}, dataLen::Csize_t, logPath::Ptr{Cwchar_t})::Cint
  data = Vector{Data}(unsafe_wrap(Array, dataPtr, dataLen))
  logPathJ = wchartostring(logPath)
  Foo.baz(data, logPathJ)
end
