solution "mruby-test"
  configurations {"Release", "Debug"}
  location "build"

project "mruby-test"
  language "C++"
  kind     "ConsoleApp"
  flags    {"ExtraWarnings"}

  files {
      "src/main.cpp"
  }

  links { "mruby"}
  libdirs { "../../../Ruby/mruby/lib/" }
  includedirs { "../../../Ruby/mruby/include/" }
  buildoptions {"-std=gnu++0x"}
  
  configuration "Release"
    targetdir "bin/release"
    defines   {"NDEBUG"}
    flags     {"Optimize"}

  configuration "Debug"
    targetdir "bin/debug"
    defines   {"_DEBUG", "DEBUG"}
    flags     {"Symbols"}
    
