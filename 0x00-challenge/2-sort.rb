#!/usr/bin/ruby
#
### 
#
#  Sort integer arguments (ascending) 
#
###

result = []
ARGV.each do |arg|
    # skip if not an integer
    next if arg !~ /^-?[0-9]+$/

    # convert to integer
    i_arg = arg.to_i
    
    # insert result at the right position
    is_inserted = false
    i = 0
    l = result.size
    while !is_inserted && i < l do
        if result[i] < i_arg
            i += 1
        else
            result.insert(i, i_arg)  # Insert the element at the correct position
            is_inserted = true
            break
        end
    end
    result << i_arg if !is_inserted  # If not inserted, append it at the end
end

puts result
