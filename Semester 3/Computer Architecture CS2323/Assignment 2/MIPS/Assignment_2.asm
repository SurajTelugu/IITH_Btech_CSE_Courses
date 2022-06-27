.data 
      OpenMessage: .asciiz "Number of Comparisions in Insertion Sort Algorithm using MIPS Assembly Language \n \n"
      Enter_a_Msg: .asciiz "Enter the Scale factor (a): " 
      Enter_r_Msg: .asciiz "Enter the Common ratio (r) : "
      Ascend_Msg:  .asciiz "The Ascending order of the GP is : "
      Decend_Msg:  .asciiz "The Decending order of the GP is : "
      Random_Msg:  .asciiz "The Random order of the GP is : "
      Isort_Msg:   .asciiz "In insertion sort (after sorting the above sequences) \n"
      Acomp_Msg:   .asciiz "Number of comparisions ascending order took is: "
      Dcomp_Msg:   .asciiz "Number of comparisions decending order took is: "
      Rcomp_Msg:   .asciiz "Number of comparisions random order took is: "
          Newline: .asciiz "\n"
            Space: .asciiz " "

      
        N:         .word  10   # Global variable N = 10
      asc:         .space 40  # Ascending order array of size 10
      dsc:	   .space 40  # Ascending order array of size 10
      rand:	   .space 40  # Ascending order array of size 10
      

.text
      .globl	Main
      
      Main:
            la $a1 OpenMessage #Displaying an open message
            jal PrintMessage
            
            lw $s0,N  #$s0 has size of array N = 10 
            
           
            la $a1 Enter_a_Msg  #displaying message to tell user to enter a
            jal PrintMessage
            
            li $v0 5 #syscall for taking integer input from user is 5
            syscall
            move $s1 $v0 # $s1 stores the scale factor a
                
            la $a1 Enter_r_Msg #displaying message to tell user to enter r
            jal PrintMessage
            
            li $v0 5
            syscall 
            move $s2 $v0  #$s2 stores the common ratio r
            
	    la $s4, asc # Let Ascending array be stored in $s4 
	    sw $s1, 0($s4)
	    
	    
	    addi $t0, $zero, 1 # $t0 = i
	    
	     Ascarray:  
	               bge $t0,$s0 Ascdone
   	               sll $t1, $t0, 2 # $t1 = i * 4
   	               add $t1, $t1, $s4  # address of asc[i]
   	               lw $t2,-4($t1) # t2 = arr[i-1]
   	               mul $t2,$t2,$s2  # asc[i] = asc[i-1] * r 
   	               sw $t2,0($t1)  
   	               addi $t0,$t0,1     
   	               j Ascarray 
   
             Ascdone:
             
             la $s5,dsc # Let Decending array be stored in $s5
             sw $s1, 36($s5) # dsc[9] = a
             lw $t3, 36($s4)
             sw $t3, 0($s5) # dsc[0] = asc[9]
             
             addi $t0, $zero, 1 # $s3 = i
             subi $t3, $s0, -1 # N-1
             
             Dscarray:  #Finding Decending array as reverse of Ascending array
	               beq $t0, $t3 Dscdone
   	               sll $t1,  $t0, 2 
   	               add $t1, $t1, $s4  
   	               lw $t2, 0($t1)
   	               sub $t4,$t3,$t0
   	               addi $t4, $t4, -2
   	               sll $t4, $t4, 2
   	               add $t4, $t4, $s5
   	               sw $t2, 0($t4)  
   	               addi $t0,$t0,1     
   	               j Dscarray 
   
             Dscdone:
             
             la $s6, rand # Let Random array be stored in $s6
             move $a0, $s1
             move $a1, $s2
             move $a2, $s6
             jal randomarray # Getting a random array 
             
             #Printing ascending array
             la $a1 Ascend_Msg
             jal PrintMessage
             la $a0, asc
             jal printarray
             
             #Printing ascending array
             la $a1 Decend_Msg
             jal PrintMessage
             la $a0, dsc
             jal printarray
             
             #Printing random array
             la $a1 Random_Msg
             jal PrintMessage
             la $a0 rand
             jal printarray
             
             la $a1 Newline
             jal PrintMessage
             
            # Applying Insertion sort to Ascending order 
            la $a0, asc
            jal Insertion_Sort
            move $t1, $v1
            
            # Printing Numner of comparisions Insertion sort took for Ascending order 
            la $a1 Acomp_Msg
            jal PrintMessage
            li	$v0, 1
	    move $a0, $t1
	    syscall
	    la $a1 Newline
            jal PrintMessage
            
            # Applying Insertion sort to Decending order   
	    la $a0, dsc
            jal Insertion_Sort
            move $t1, $v1
            
            # Printing Numner of comparisions Insertion sort took for Decending order
            la $a1 Dcomp_Msg
            jal PrintMessage
            li	$v0, 1
	    move $a0, $t1
	    syscall
	    la $a1 Newline
            jal PrintMessage
            
            # Applying Insertion sort to Random order      
	    la $a0, rand
            jal Insertion_Sort
            move $t1, $v1
            
            # Printing Numner of comparisions Insertion sort took for Random order
            la $a1 Rcomp_Msg
            jal PrintMessage
            li	$v0, 1
	    move $a0, $t1
	    syscall
	    
	    jal Exit
            
      Exit:
	    li	$v0, 10  #syscall for exiting the program is 10
	    syscall
	    
     PrintMessage:
                   move $t0, $a1
                   li $v0 4
                   move $a0, $t0
                   syscall
                   jr $ra
                   
                   			
	      
     # Function to print an array 
     printarray:
                 move $t0, $a0
	         move $t1, $s0 
	         li $t2, 0
                 printloop:
	                     bge $t2, $t1, printexit
	                     li	$v0, 1
	                     lw	$a0, 0($t0)
	                     syscall
	                     li	$v0, 4
	                     la	$a0, Space
	                     syscall
	                     addi $t0, $t0, 4
	                     addi $t2, $t2, 1
	                     j printloop
	
	
                 printexit:
	                     li	$v0, 4
	                     la	$a0, Newline
	                     syscall
	                     jr $ra 
	              
     #Function to create random array
     randomarray:
                 move $t0, $a0
                 move $t1, $a1
                 move $t2, $a2
                 
                 #First construct an ascending array and then randomise it later
                 
                
	         sw $s1, 0($t2)
	         
	         addi $t3, $zero, 1 # $t0 = i
                 Randarray:  
	                  bge $t3,$s0 Randone
   	                  sll $t4, $t3, 2 # $t1 = i * 4
   	                  add $t4, $t4, $t2  # address of rand[i]
   	                  lw $t5,-4($t4) # t2 = rand[i-1]
   	                  mul $t5,$t5,$s2  # rand[i] = rand[i-1] * r 
   	                  sw $t5,0($t4)  
   	                  addi $t3,$t3,1     
   	                  j Randarray 
   
                 Randone:
               
                 addi $t3, $zero, 1
                 addi $t4, $s0, -1
                 Swaploop: 
                           bge $t3, $t4, Endswap         # This loop Swaps elements randomly 
                           
                           li $a1, 9  # Uperlimit = 9
	                   li $v0, 42 # System call to call a random integer is 42
 	                   syscall
 	                   
 	                   move $t5, $a0
 	                   sub $t6,$s0,$t3
        		   div $t5,$t6
        		   mfhi $t5
        
        			#swapping the elements in array
        			sll $t6,$t3,2
        			sll $t7,$t5,2
        			add $t6,$t6,$a2
        			add $t7,$t7,$a2
        			lw $t8,0($t6)
        		        lw $t9,0($t7)
        		        sw $t9,0($t6)
        		        sw $t8,0($t7) 
        			
        			addi $t3,$t3,1
   				j Swaploop
 	                   
 	                  
 	   
 	          Endswap:
	                     jr $ra

     
     #Insertion sort algorithm function
     Insertion_Sort:
                    
	               add $t0, $zero, $a0
	               move $t1, $s0
	               addi $v1, $zero, 0
	               li $t2, 1
                       
                       Loop1:
	                      add $t0, $zero, $a0
	                      bge $t2, $t1, Endloop1
	                      move $t3, $t2
		       
		       Loop2:
			        add $t0, $zero, $a0
				mul $t5, $t3, 4
				add $t0, $t0, $t5
				ble $t3, $zero, Endloop2
				lw $t7, 0($t0)
			        lw $t6, -4($t0)
			        addi $v1, $v1, 1
				bge $t7, $t6, Endloop2
				lw $t4, 0($t0)
				sw $t6, 0($t0)
				sw $t4, -4($t0)
				subi $t3, $t3, 1
				j Loop2
            
                     Endloop2:
				addi $t2, $t2, 1
				j Loop1
          
                     Endloop1:
                                jr $ra                                                                                  
