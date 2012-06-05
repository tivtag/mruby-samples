#include <iostream>
#include <fstream>

#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <mruby/variable.h>

int main()
{
   // Read ruby code
   std::ifstream ifs("src/sample-1.rb");
   
   if(!ifs)
   {
      std::cout << "ruby input file not found " << std::endl;
      return -1;
   }
   
   std::string code((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

   // Debug output code
   std::cout << std::endl
             << "Nya from C++! The ruby code is: " << std::endl << std::endl
             << code << std::endl;  

   // Start mrb
   mrb_state* mrb = mrb_open();

   // Parse
   mrb_parser_state* p = mrb_parse_string(mrb, code.c_str());
   int n = mrb_generate_code(mrb, p->tree);

   // Set global variable
   mrb_sym my_global = mrb_intern(mrb, "$my_global");
   mrb_gv_set(mrb, my_global, mrb_float_value(12.34f)); 

   // Execute code
   mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_top_self(mrb));

   // Read global variable
   float val = mrb_float(mrb_gv_get(mrb, my_global));
   std::cout << std::endl << "Ruby Global: " << val << std::endl;

   // Execute method
   mrb_funcall(mrb, mrb_top_self(mrb), "inc_global", 0);

   // Read global variable
   val = mrb_float(mrb_gv_get(mrb, my_global));
   std::cout << std::endl << "Ruby Global: " << val << std::endl;

   // Sleep well, mruby
   mrb_close(mrb);
   std::cin.ignore();
   return 0;
}
