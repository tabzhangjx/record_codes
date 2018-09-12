	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI0_0:
	.quad	4616527388026811187     ## double 4.2999999999999998
LCPI0_1:
	.quad	4617315517961601024     ## double 5
LCPI0_2:
	.quad	4616414798036126925     ## double 4.2000000000000002
LCPI0_3:
	.quad	4616189618054758400     ## double 4
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$240, %rsp
	leaq	-104(%rbp), %rdi
	leaq	-108(%rbp), %rsi
	movl	$0, -100(%rbp)
	movl	$4, -104(%rbp)
	movl	$5, -108(%rbp)
	callq	__Z3maxIiERKT_S2_S2_
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movl	(%rax), %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rdi
	movq	%rax, -88(%rbp)
	movq	%rdi, -96(%rbp)
	movq	-88(%rbp), %rdi
	callq	*-96(%rbp)
	leaq	-120(%rbp), %rdi
	leaq	-128(%rbp), %rsi
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI0_2(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	%xmm1, -120(%rbp)
	movsd	%xmm0, -128(%rbp)
	movq	%rax, -192(%rbp)        ## 8-byte Spill
	callq	__Z3maxIdERKT_S2_S2_
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rsi
	movq	%rax, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	-72(%rbp), %rdi
	callq	*-80(%rbp)
	leaq	-136(%rbp), %rdi
	leaq	-144(%rbp), %rsi
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI0_3(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	%xmm1, -136(%rbp)
	movsd	%xmm0, -144(%rbp)
	movq	%rax, -200(%rbp)        ## 8-byte Spill
	callq	__Z3maxIdERKT_S2_S2_
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rsi
	movq	%rax, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rdi
	callq	*-64(%rbp)
	leaq	-152(%rbp), %rdi
	leaq	-160(%rbp), %rsi
	movsd	LCPI0_1(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI0_2(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	%xmm1, -152(%rbp)
	movsd	%xmm0, -160(%rbp)
	movq	%rax, -208(%rbp)        ## 8-byte Spill
	callq	__Z3maxIdERKT_S2_S2_
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rsi
	movq	%rax, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rdi
	callq	*-48(%rbp)
	leaq	-168(%rbp), %rdi
	leaq	-172(%rbp), %rsi
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	%xmm0, -168(%rbp)
	movl	$4, -172(%rbp)
	movq	%rax, -216(%rbp)        ## 8-byte Spill
	callq	__Z4max2IdiET_RKS0_RKT0_
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rsi
	movq	%rax, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rdi
	callq	*-32(%rbp)
	leaq	-176(%rbp), %rdi
	leaq	-184(%rbp), %rsi
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movl	$3, -176(%rbp)
	movsd	%xmm0, -184(%rbp)
	movq	%rax, -224(%rbp)        ## 8-byte Spill
	callq	__Z4max2IidET_RKS0_RKT0_
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movl	%eax, %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rdi
	movq	%rax, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movq	-8(%rbp), %rdi
	callq	*-16(%rbp)
	xorl	%esi, %esi
	movq	%rax, -232(%rbp)        ## 8-byte Spill
	movl	%esi, %eax
	addq	$240, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z3maxIiERKT_S2_S2_    ## -- Begin function _Z3maxIiERKT_S2_S2_
	.weak_definition	__Z3maxIiERKT_S2_S2_
	.p2align	4, 0x90
__Z3maxIiERKT_S2_S2_:                   ## @_Z3maxIiERKT_S2_S2_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rsi
	movl	(%rsi), %eax
	movq	-24(%rbp), %rsi
	cmpl	(%rsi), %eax
	jne	LBB1_2
## BB#1:
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB1_6
LBB1_2:
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	cmpl	(%rax), %ecx
	jle	LBB1_4
## BB#3:
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	jmp	LBB1_5
LBB1_4:
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
LBB1_5:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -8(%rbp)
LBB1_6:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.private_extern	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_ ## -- Begin function _ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.globl	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.weak_definition	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.p2align	4, 0x90
__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_: ## @_ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -72(%rbp)
	movq	-72(%rbp), %rdi
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	%rdi, %rcx
	addq	%rax, %rcx
	movq	%rcx, -32(%rbp)
	movb	$10, -33(%rbp)
	movq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rax
	movq	%rdi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	__ZNKSt3__18ios_base6getlocEv
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
Ltmp0:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp1:
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	jmp	LBB2_1
LBB2_1:
	movb	-33(%rbp), %al
	movq	-96(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp2:
	movl	%edi, -100(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-100(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -112(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-112(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp3:
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jmp	LBB2_5
LBB2_2:
Ltmp4:
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
Ltmp5:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
Ltmp6:
	jmp	LBB2_3
LBB2_3:
	movq	-56(%rbp), %rdi
	callq	__Unwind_Resume
LBB2_4:
Ltmp7:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -120(%rbp)        ## 4-byte Spill
	callq	___clang_call_terminate
LBB2_5:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movb	-113(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	movq	-72(%rbp), %rdi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	movq	-72(%rbp), %rdi
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	movq	%rdi, %rax
	addq	$144, %rsp
	popq	%rbp
	retq
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\274"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	52                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp0-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp0
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp0-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp3-Ltmp0                     ##   Call between Ltmp0 and Ltmp3
	.long	Lset3
Lset4 = Ltmp4-Lfunc_begin0              ##     jumps to Ltmp4
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp5-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Ltmp6-Ltmp5                     ##   Call between Ltmp5 and Ltmp6
	.long	Lset6
Lset7 = Ltmp7-Lfunc_begin0              ##     jumps to Ltmp7
	.long	Lset7
	.byte	1                       ##   On action: 1
Lset8 = Ltmp6-Lfunc_begin0              ## >> Call Site 4 <<
	.long	Lset8
Lset9 = Lfunc_end0-Ltmp6                ##   Call between Ltmp6 and Lfunc_end0
	.long	Lset9
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z3maxIdERKT_S2_S2_    ## -- Begin function _Z3maxIdERKT_S2_S2_
	.weak_definition	__Z3maxIdERKT_S2_S2_
	.p2align	4, 0x90
__Z3maxIdERKT_S2_S2_:                   ## @_Z3maxIdERKT_S2_S2_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rsi
	movsd	(%rsi), %xmm0           ## xmm0 = mem[0],zero
	movq	-24(%rbp), %rsi
	ucomisd	(%rsi), %xmm0
	jne	LBB3_2
	jp	LBB3_2
## BB#1:
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB3_6
LBB3_2:
	movq	-16(%rbp), %rax
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	movq	-24(%rbp), %rax
	ucomisd	(%rax), %xmm0
	jbe	LBB3_4
## BB#3:
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	jmp	LBB3_5
LBB3_4:
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
LBB3_5:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -8(%rbp)
LBB3_6:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z4max2IdiET_RKS0_RKT0_ ## -- Begin function _Z4max2IdiET_RKS0_RKT0_
	.weak_definition	__Z4max2IdiET_RKS0_RKT0_
	.p2align	4, 0x90
__Z4max2IdiET_RKS0_RKT0_:               ## @_Z4max2IdiET_RKS0_RKT0_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rsi
	movsd	(%rsi), %xmm0           ## xmm0 = mem[0],zero
	movq	-24(%rbp), %rsi
	cvtsi2sdl	(%rsi), %xmm1
	ucomisd	%xmm1, %xmm0
	jne	LBB4_2
	jp	LBB4_2
## BB#1:
	movq	-16(%rbp), %rax
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	movsd	%xmm0, -8(%rbp)
	jmp	LBB4_6
LBB4_2:
	movq	-16(%rbp), %rax
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	movq	-24(%rbp), %rax
	cvtsi2sdl	(%rax), %xmm1
	ucomisd	%xmm1, %xmm0
	jbe	LBB4_4
## BB#3:
	movq	-16(%rbp), %rax
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	movsd	%xmm0, -32(%rbp)        ## 8-byte Spill
	jmp	LBB4_5
LBB4_4:
	movq	-24(%rbp), %rax
	cvtsi2sdl	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)        ## 8-byte Spill
LBB4_5:
	movsd	-32(%rbp), %xmm0        ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	movsd	%xmm0, -8(%rbp)
LBB4_6:
	movsd	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z4max2IidET_RKS0_RKT0_ ## -- Begin function _Z4max2IidET_RKS0_RKT0_
	.weak_definition	__Z4max2IidET_RKS0_RKT0_
	.p2align	4, 0x90
__Z4max2IidET_RKS0_RKT0_:               ## @_Z4max2IidET_RKS0_RKT0_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi15:
	.cfi_def_cfa_offset 16
Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi17:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rsi
	cvtsi2sdl	(%rsi), %xmm0
	movq	-24(%rbp), %rsi
	ucomisd	(%rsi), %xmm0
	jne	LBB5_2
	jp	LBB5_2
## BB#1:
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -4(%rbp)
	jmp	LBB5_6
LBB5_2:
	movq	-16(%rbp), %rax
	cvtsi2sdl	(%rax), %xmm0
	movq	-24(%rbp), %rax
	ucomisd	(%rax), %xmm0
	jbe	LBB5_4
## BB#3:
	movq	-16(%rbp), %rax
	cvtsi2sdl	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)        ## 8-byte Spill
	jmp	LBB5_5
LBB5_4:
	movq	-24(%rbp), %rax
	movsd	(%rax), %xmm0           ## xmm0 = mem[0],zero
	movsd	%xmm0, -32(%rbp)        ## 8-byte Spill
LBB5_5:
	movsd	-32(%rbp), %xmm0        ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	cvttsd2si	%xmm0, %eax
	movl	%eax, -4(%rbp)
LBB5_6:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.private_extern	___clang_call_terminate ## -- Begin function __clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev
                                        ## -- End function

.subsections_via_symbols
