
_reset :
     bl main
	 b .
 .thumb_func
	 
vector_handler :
     b _reset


.section .vectors
.word 0x20001000 /*stack-top*/
.word _reset     /*reset*/
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler


