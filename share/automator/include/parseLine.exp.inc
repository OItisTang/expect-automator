#************************************************ 
# parse a line follow the syntax:
#   '#' comment
#   '!' will be executed as expect command
#   '>' expected output
#       '>glob>'    use "glob" matching scheme,
#                     default, same as '>'
#       '>exact>'   use "exact" matching scheme
#       '>regex>'   use "regex" matching scheme
#   '<' input which will be sent to target
#       '<newline<' a '\n' will be appended,
#                     default, same as '<'
#       '<exact<'   keep the following untouched
#       '<passwd<'  same as '<newline<' but do not expect
#                     the input been echoed back
#                     used when asking for password
#   (no prefix)     same as '<'
#
#
# @PARAMS
# fd     - file fd
# type   - var used to return input type
# option - var used to return input option
# value  - var used to return input value
# 
# @RETURN
# return 1 if read successfully, otherwise 0
#************************************************ 
proc parseLine {fd type option value} {
    upvar $type retType
    upvar $option retOption
    upvar $value retValue

    # read a line from fd
    while {[set lineLen [gets $fd tmpLine]] >= 0} {
        # blank line
        if { $lineLen == 0 } continue
 
        # trim whitespace
        set tmpLine [string trim $tmpLine]
        if { [string length $tmpLine] == 0 } continue

        set prefix [string index $tmpLine 0]
        
        if { $prefix == "#" } {
            set retType "#"
            set retOption ""
            set retValue [string range $tmpLine 1 end]
            return 1
        } elseif { $prefix == "!" } {
            set retType "!"
            set retOption ""
            set tmpLine [string range $tmpLine 1 end]
            set retValue [string trim $tmpLine]
            return 1
        } elseif { $prefix == ">" } {
            set retType ">"
            set retOption "glob"
            
            set tmpLine [string range $tmpLine 1 end]
            if { [string match "glob>*" $tmpLine] == 1 } {
                set retOption "glob"
                set tmpLine [string range $tmpLine [string length "glob>"] end]
            } elseif { [string match "exact>*" $tmpLine] == 1 } {
                set retOption "exact"
                set tmpLine [string range $tmpLine [string length "exact>"] end]
            } elseif { [string match "regexp>*" $tmpLine] == 1 } {
                set retOption "regexp"
                set tmpLine [string range $tmpLine [string length "regexp>"] end]
            }
            
            set retValue [string trim $tmpLine]
            return 1
        } else {
            set retType "<"
            set retOption "newline"
            
            if { $prefix == "<" } {
                set tmpLine [string range $tmpLine 1 end]
                if { [string match "newline<*" $tmpLine] == 1 } {
                    set retOption "newline"
                    set tmpLine [string range $tmpLine [string length "newline<"] end]
                } elseif { [string match "exact<*" $tmpLine] == 1 } {
                    set retOption "exact"
                    set tmpLine [string range $tmpLine [string length "exact<"] end]
                } elseif { [string match "passwd<*" $tmpLine] == 1 } {
                    set retOption "passwd"
                    set tmpLine [string range $tmpLine [string length "passwd<"] end]
                }
            }

            set retValue [string trim $tmpLine]
            return 1
        }
    }

    return 0
}
