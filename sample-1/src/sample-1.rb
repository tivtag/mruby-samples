puts "Meow from mruby! #{$my_global}"

def inc_global
  puts 'inc_global() called'
  $my_global = $my_global * 2
end

inc_global()

