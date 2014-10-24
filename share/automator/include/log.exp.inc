namespace eval log_exp_inc {
    variable dbgLogFlag 0
    variable errLogFlag 0
}

#************************************************ 
# set debug log flag routine
#
# @PARAMS
# flag - 0 disable, 1 enable
#************************************************ 
proc setDbgLogFlag {flag} {
    set log_exp_inc::dbgLogFlag $flag
}

#************************************************ 
# set error log flag routine
#
# @PARAMS
# flag - 0 disable, 1 enable
#************************************************ 
proc setErrLogFlag {flag} {
    set log_exp_inc::errLogFlag $flag
}

#************************************************ 
# debug output routine
#
# @PARAMS
# arg - variable length arguments
#************************************************ 
proc dbgLog {arg} {
    if {$log_exp_inc::dbgLogFlag} {
        puts stdout "$arg"
    }
}

#************************************************ 
# error output routine
#
# @PARAMS
# arg - variable length arguments
#************************************************ 
proc errLog {arg} {
    if {$log_exp_inc::errLogFlag} {
        puts stderr "$arg"
    }
}
