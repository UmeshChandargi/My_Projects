transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -sv -work work +incdir+C:/my_folder/assignments/fsoc/Lab_assignment3/sha1_Implimentation_Lab3/sha1_Implimentation {C:/my_folder/assignments/fsoc/Lab_assignment3/sha1_Implimentation_Lab3/sha1_Implimentation/sha1_Implimentation.sv}

vlog -sv -work work +incdir+C:/my_folder/assignments/fsoc/Lab_assignment3/sha1_Implimentation_Lab3/sha1_Implimentation {C:/my_folder/assignments/fsoc/Lab_assignment3/sha1_Implimentation_Lab3/sha1_Implimentation/sha1_Implimentation_tb.sv}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L fiftyfivenm_ver -L rtl_work -L work -voptargs="+acc"  sha1_Implimentation_tb

add wave *
view structure
view signals
run -all
