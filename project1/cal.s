	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-80]!           ; 16-byte Folded Spill
	stp	x24, x23, [sp, #16]             ; 16-byte Folded Spill
	stp	x22, x21, [sp, #32]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #48]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	mov	w9, #7088
	movk	w9, #6, lsl #16
Lloh0:
	adrp	x16, ___chkstk_darwin@GOTPAGE
Lloh1:
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #97, lsl #12            ; =397312
	sub	sp, sp, #2992
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	.cfi_offset w23, -56
	.cfi_offset w24, -64
	.cfi_offset w27, -72
	.cfi_offset w28, -80
Lloh2:
	adrp	x8, ___stack_chk_guard@GOTPAGE
Lloh3:
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
Lloh4:
	ldr	x8, [x8]
	stur	x8, [x29, #-72]
	mov	w0, #10005
	bl	_malloc
	mov	x19, x0
	str	x0, [sp]
Lloh5:
	adrp	x0, l_.str@PAGE
Lloh6:
	add	x0, x0, l_.str@PAGEOFF
	bl	_scanf
	cmn	w0, #1
	b.eq	LBB0_5
; %bb.1:
	mov	w23, #0
	mov	w21, #40
	add	x22, sp, #96
Lloh7:
	adrp	x20, l_.str@PAGE
Lloh8:
	add	x20, x20, l_.str@PAGEOFF
	b	LBB0_3
LBB0_2:                                 ;   in Loop: Header=BB0_3 Depth=1
	mov	x0, x19
	bl	_Lexer
	ldur	q0, [sp, #56]
	ldur	q1, [sp, #72]
	stp	q0, q1, [x24]
	ldr	x8, [sp, #88]
	str	x8, [x24, #32]
	add	w1, w23, #1
	add	x8, sp, #56
	add	x0, sp, #96
	bl	_Parser
	ldur	q0, [sp, #56]
	ldur	q1, [sp, #72]
	stp	q0, q1, [sp, #16]
	ldr	x8, [sp, #88]
	str	x8, [sp, #48]
	add	x0, sp, #16
	bl	_Output
	mov	w23, #0
	str	x19, [sp]
	mov	x0, x20
	bl	_scanf
	cmn	w0, #1
	b.eq	LBB0_5
LBB0_3:                                 ; =>This Inner Loop Header: Depth=1
	bl	_getchar
	smaddl	x24, w23, w21, x22
	add	x8, sp, #56
	cmp	w0, #10
	b.eq	LBB0_2
; %bb.4:                                ;   in Loop: Header=BB0_3 Depth=1
	mov	x0, x19
	bl	_Lexer
	ldur	q0, [sp, #56]
	ldur	q1, [sp, #72]
	stp	q0, q1, [x24]
	ldr	x8, [sp, #88]
	str	x8, [x24, #32]
	add	w23, w23, #1
	str	x19, [sp]
	mov	x0, x20
	bl	_scanf
	cmn	w0, #1
	b.ne	LBB0_3
LBB0_5:
	ldur	x8, [x29, #-72]
Lloh9:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh10:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh11:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB0_7
; %bb.6:
	mov	w0, #0
	add	sp, sp, #97, lsl #12            ; =397312
	add	sp, sp, #2992
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #48]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #32]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #80             ; 16-byte Folded Reload
	ret
LBB0_7:
	bl	___stack_chk_fail
	.loh AdrpAdd	Lloh5, Lloh6
	.loh AdrpLdrGotLdr	Lloh2, Lloh3, Lloh4
	.loh AdrpLdrGot	Lloh0, Lloh1
	.loh AdrpAdd	Lloh7, Lloh8
	.loh AdrpLdrGotLdr	Lloh9, Lloh10, Lloh11
	.cfi_endproc
                                        ; -- End function
	.globl	_Lexer                          ; -- Begin function Lexer
	.p2align	2
_Lexer:                                 ; @Lexer
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	stp	x26, x25, [sp, #16]             ; 16-byte Folded Spill
	stp	x24, x23, [sp, #32]             ; 16-byte Folded Spill
	stp	x22, x21, [sp, #48]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #64]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	.cfi_offset w23, -56
	.cfi_offset w24, -64
	.cfi_offset w25, -72
	.cfi_offset w26, -80
	mov	x19, x0
	mov	x20, x8
	str	xzr, [x8, #32]
	movi.2d	v0, #0000000000000000
	stp	q0, q0, [x8]
	bl	_strlen
	mov	x21, x0
Lloh12:
	adrp	x1, l_.str.4@PAGE
Lloh13:
	add	x1, x1, l_.str.4@PAGEOFF
	mov	x0, x19
	bl	_strcmp
	cbz	w0, LBB1_9
; %bb.1:
Lloh14:
	adrp	x1, l_.str.5@PAGE
Lloh15:
	add	x1, x1, l_.str.5@PAGEOFF
	mov	x0, x19
	bl	_strcmp
	cbz	w0, LBB1_9
; %bb.2:
Lloh16:
	adrp	x1, l_.str.6@PAGE
Lloh17:
	add	x1, x1, l_.str.6@PAGEOFF
	mov	x0, x19
	bl	_strcmp
	cbz	w0, LBB1_9
; %bb.3:
Lloh18:
	adrp	x1, l_.str.7@PAGE
Lloh19:
	add	x1, x1, l_.str.7@PAGEOFF
	mov	x0, x19
	bl	_strcmp
	cbz	w0, LBB1_9
; %bb.4:
Lloh20:
	adrp	x1, l_.str.8@PAGE
Lloh21:
	add	x1, x1, l_.str.8@PAGEOFF
	mov	x0, x19
	bl	_strcmp
	cbz	w0, LBB1_9
; %bb.5:
Lloh22:
	adrp	x1, l_.str.9@PAGE
Lloh23:
	add	x1, x1, l_.str.9@PAGEOFF
	mov	x0, x19
	bl	_strcmp
	cbz	w0, LBB1_9
; %bb.6:
Lloh24:
	adrp	x1, l_.str.10@PAGE
Lloh25:
	add	x1, x1, l_.str.10@PAGEOFF
	mov	x0, x19
	bl	_strcmp
	cbz	w0, LBB1_9
; %bb.7:
	mov	x0, x19
	mov	w1, #46
	bl	_strchr
	mov	x22, x0
	ldrsb	w24, [x19]
	cmp	w24, #48
	b.ne	LBB1_11
; %bb.8:
	ldrsb	w8, [x19, #1]
	sub	w8, w8, #48
	cmp	w8, #9
	cset	w25, hi
	b	LBB1_12
LBB1_9:
	mov	w8, #4
LBB1_10:
	str	w8, [x20], #8
	mov	x0, x20
	mov	x1, x19
	mov	w2, #32
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #64]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #48]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #32]             ; 16-byte Folded Reload
	ldp	x26, x25, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #96
	b	___strcpy_chk
LBB1_11:
	mov	w25, #1
LBB1_12:
	cbz	x22, LBB1_26
; %bb.13:
	sub	x8, x22, x19
	sub	w9, w21, #1
	cmp	x8, w9, sxtw
	b.ge	LBB1_26
; %bb.14:
	cmp	x22, x19
	b.eq	LBB1_26
; %bb.15:
	add	x23, x22, #1
	mov	x0, x23
	mov	w1, #46
	bl	_strchr
	cbnz	x0, LBB1_26
; %bb.16:
	cmp	x22, x19
	b.ls	LBB1_21
; %bb.17:
	mov	x8, x19
	b	LBB1_19
LBB1_18:                                ;   in Loop: Header=BB1_19 Depth=1
	ldrsb	w9, [x8]
	sub	w9, w9, #48
	cmp	w9, #10
	cset	w25, lo
	add	x8, x8, #1
	cmp	x8, x22
	b.hs	LBB1_21
LBB1_19:                                ; =>This Inner Loop Header: Depth=1
	tbnz	w25, #0, LBB1_18
; %bb.20:                               ;   in Loop: Header=BB1_19 Depth=1
	mov	w25, #0
	add	x8, x8, #1
	cmp	x8, x22
	b.lo	LBB1_19
LBB1_21:
	ldrb	w9, [x23]
	cbz	w9, LBB1_24
; %bb.22:
	add	x8, x22, #2
LBB1_23:                                ; =>This Inner Loop Header: Depth=1
	sxtb	w9, w9
	sub	w9, w9, #48
	cmp	w9, #10
	cset	w9, lo
	and	w25, w25, w9
	ldrb	w9, [x8], #1
	cbnz	w9, LBB1_23
LBB1_24:
	cbz	w25, LBB1_26
; %bb.25:
	mov	w8, #2
	str	w8, [x20], #8
	str	x20, [sp]
Lloh26:
	adrp	x1, l_.str.11@PAGE
Lloh27:
	add	x1, x1, l_.str.11@PAGEOFF
	b	LBB1_42
LBB1_26:
	subs	w23, w24, #48
	cset	w22, ne
	mov	x0, x19
	bl	_strlen
	cmp	x0, #2
	cset	w8, lo
	orr	w9, w8, w22
	cmp	w21, #1
	b.lt	LBB1_40
; %bb.27:
	mov	x8, #0
	and	x22, x21, #0xffffffff
	b	LBB1_29
LBB1_28:                                ;   in Loop: Header=BB1_29 Depth=1
	mov	w9, #0
	add	x8, x8, #1
	cmp	x8, x22
	b.eq	LBB1_32
LBB1_29:                                ; =>This Inner Loop Header: Depth=1
	tbz	w9, #0, LBB1_28
; %bb.30:                               ;   in Loop: Header=BB1_29 Depth=1
	ldrsb	w9, [x19, x8]
	sub	w10, w9, #48
	cmp	w10, #10
	cset	w9, lo
	add	x8, x8, #1
	cmp	x8, x22
	b.ne	LBB1_29
; %bb.31:
	cmp	w10, #10
	b.lo	LBB1_41
LBB1_32:
	cmp	w23, #9
	cset	w8, hi
Lloh28:
	adrp	x23, __DefaultRuneLocale@GOTPAGE
Lloh29:
	ldr	x23, [x23, __DefaultRuneLocale@GOTPAGEOFF]
	mov	w24, #1280
	mov	x25, x19
	b	LBB1_34
LBB1_33:                                ;   in Loop: Header=BB1_34 Depth=1
	mov	w8, #0
	add	x25, x25, #1
	subs	x22, x22, #1
	b.eq	LBB1_39
LBB1_34:                                ; =>This Inner Loop Header: Depth=1
	tbz	w8, #0, LBB1_33
; %bb.35:                               ;   in Loop: Header=BB1_34 Depth=1
	ldrsb	w21, [x25]
	tbnz	w21, #31, LBB1_37
; %bb.36:                               ;   in Loop: Header=BB1_34 Depth=1
	add	x8, x23, w21, uxtw #2
	ldr	w8, [x8, #60]
	and	w0, w8, w24
	b	LBB1_38
LBB1_37:                                ;   in Loop: Header=BB1_34 Depth=1
	mov	x0, x21
	mov	w1, #1280
	bl	___maskrune
LBB1_38:                                ;   in Loop: Header=BB1_34 Depth=1
	cmp	w0, #0
	cset	w8, ne
	cmp	w21, #95
	cset	w9, eq
	orr	w8, w8, w9
	add	x25, x25, #1
	subs	x22, x22, #1
	b.ne	LBB1_34
LBB1_39:
	tbz	w8, #0, LBB1_43
	b	LBB1_45
LBB1_40:
	tbz	w9, #0, LBB1_44
LBB1_41:
	mov	w8, #1
	str	w8, [x20], #8
	str	x20, [sp]
Lloh30:
	adrp	x1, l_.str.12@PAGE
Lloh31:
	add	x1, x1, l_.str.12@PAGEOFF
LBB1_42:
	mov	x0, x19
	bl	_sscanf
LBB1_43:
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #64]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #48]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #32]             ; 16-byte Folded Reload
	ldp	x26, x25, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
LBB1_44:
	cmp	w23, #9
	b.ls	LBB1_43
LBB1_45:
	mov	w8, #3
	b	LBB1_10
	.loh AdrpAdd	Lloh12, Lloh13
	.loh AdrpAdd	Lloh14, Lloh15
	.loh AdrpAdd	Lloh16, Lloh17
	.loh AdrpAdd	Lloh18, Lloh19
	.loh AdrpAdd	Lloh20, Lloh21
	.loh AdrpAdd	Lloh22, Lloh23
	.loh AdrpAdd	Lloh24, Lloh25
	.loh AdrpAdd	Lloh26, Lloh27
	.loh AdrpLdrGot	Lloh28, Lloh29
	.loh AdrpAdd	Lloh30, Lloh31
	.cfi_endproc
                                        ; -- End function
	.globl	_Parser                         ; -- Begin function Parser
	.p2align	2
_Parser:                                ; @Parser
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #288
	stp	x28, x27, [sp, #208]            ; 16-byte Folded Spill
	stp	x24, x23, [sp, #224]            ; 16-byte Folded Spill
	stp	x22, x21, [sp, #240]            ; 16-byte Folded Spill
	stp	x20, x19, [sp, #256]            ; 16-byte Folded Spill
	stp	x29, x30, [sp, #272]            ; 16-byte Folded Spill
	add	x29, sp, #272
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	.cfi_offset w23, -56
	.cfi_offset w24, -64
	.cfi_offset w27, -72
	.cfi_offset w28, -80
	mov	x19, x8
Lloh32:
	adrp	x8, ___stack_chk_guard@GOTPAGE
Lloh33:
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
Lloh34:
	ldr	x8, [x8]
	stur	x8, [x29, #-72]
	stur	xzr, [x29, #-80]
	movi.2d	v0, #0000000000000000
	stp	q0, q0, [x29, #-112]
	cmp	w1, #0
	b.le	LBB2_12
; %bb.1:
	mov	x20, x1
	mov	x21, x0
	subs	w22, w1, #1
	b.ne	LBB2_3
; %bb.2:
	ldp	q0, q1, [x21]
	stp	q0, q1, [x19]
	ldr	x8, [x21, #32]
	b	LBB2_13
LBB2_3:
	mov	x0, x21
	mov	x1, x20
	bl	_CheckParen
	cmn	w0, #1
	b.eq	LBB2_12
; %bb.4:
	cmp	w0, #1
	b.ne	LBB2_7
; %bb.5:
	ldur	x8, [x29, #-72]
Lloh35:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh36:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh37:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB2_16
; %bb.6:
	add	x0, x21, #40
	sub	w1, w20, #2
	mov	x8, x19
	ldp	x29, x30, [sp, #272]            ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #256]            ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #240]            ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #224]            ; 16-byte Folded Reload
	ldp	x28, x27, [sp, #208]            ; 16-byte Folded Reload
	add	sp, sp, #288
	b	_Parser
LBB2_7:
	mov	x0, x21
	mov	x1, x20
	bl	_MainOperator
	cbz	x0, LBB2_10
; %bb.8:
	mov	x23, x0
	ldr	w8, [x0]
	cbz	w8, LBB2_12
; %bb.9:
	ldrsb	w22, [x23, #8]
	sub	x8, x23, x21
	lsr	x8, x8, #3
	mov	w9, #52429
	movk	w9, #52428, lsl #16
	mul	w24, w8, w9
	add	x8, sp, #40
	mov	x0, x21
	mov	x1, x24
	bl	_Parser
	add	x0, x23, #40
	mvn	w8, w24
	add	w1, w8, w20
	mov	x8, sp
	bl	_Parser
	sub	x8, x29, #112
	add	x0, sp, #40
	mov	x1, sp
	mov	x2, x22
	bl	_BinaryEval
	ldp	q0, q1, [x29, #-112]
	stp	q0, q1, [x19]
	ldur	x8, [x29, #-80]
	b	LBB2_13
LBB2_10:
	mov	x0, x21
	mov	x1, x20
	bl	_MinusSupport
	cbz	x0, LBB2_12
; %bb.11:
	add	x0, x0, #40
	add	x8, sp, #120
	mov	x1, x22
	bl	_Parser
	mov	w8, #1
	str	w8, [sp, #80]
	movi.2d	v0, #0000000000000000
	stur	q0, [sp, #84]
	stur	q0, [sp, #100]
	str	wzr, [sp, #116]
	add	x0, sp, #80
	add	x1, sp, #120
	mov	x8, x19
	mov	w2, #45
	bl	_BinaryEval
	b	LBB2_14
LBB2_12:
Lloh38:
	adrp	x8, _error@PAGE
Lloh39:
	add	x8, x8, _error@PAGEOFF
	ldp	q0, q1, [x8]
	stp	q0, q1, [x19]
	ldr	x8, [x8, #32]
LBB2_13:
	str	x8, [x19, #32]
LBB2_14:
	ldur	x8, [x29, #-72]
Lloh40:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh41:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh42:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB2_16
; %bb.15:
	ldp	x29, x30, [sp, #272]            ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #256]            ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #240]            ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #224]            ; 16-byte Folded Reload
	ldp	x28, x27, [sp, #208]            ; 16-byte Folded Reload
	add	sp, sp, #288
	ret
LBB2_16:
	bl	___stack_chk_fail
	.loh AdrpLdrGotLdr	Lloh32, Lloh33, Lloh34
	.loh AdrpLdrGotLdr	Lloh35, Lloh36, Lloh37
	.loh AdrpAdd	Lloh38, Lloh39
	.loh AdrpLdrGotLdr	Lloh40, Lloh41, Lloh42
	.cfi_endproc
                                        ; -- End function
	.globl	_Output                         ; -- Begin function Output
	.p2align	2
_Output:                                ; @Output
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x22, x21, [sp, #16]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #32]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	ldr	w8, [x0]
	cmp	w8, #4
	b.hi	LBB3_17
; %bb.1:
Lloh43:
	adrp	x9, lJTI3_0@PAGE
Lloh44:
	add	x9, x9, lJTI3_0@PAGEOFF
	adr	x10, LBB3_2
	ldrb	w11, [x9, x8]
	add	x10, x10, x11, lsl #2
	br	x10
LBB3_2:
Lloh45:
	adrp	x0, l_str.13@PAGE
Lloh46:
	add	x0, x0, l_str.13@PAGEOFF
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #32]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #64
	b	_puts
LBB3_3:
	ldr	w8, [x0, #8]
	str	x8, [sp]
	b	LBB3_13
LBB3_4:
	ldr	d0, [x0, #8]
	b	LBB3_15
LBB3_5:
Lloh47:
	adrp	x8, _assignmentCnt@GOTPAGE
Lloh48:
	ldr	x8, [x8, _assignmentCnt@GOTPAGEOFF]
Lloh49:
	ldr	w22, [x8]
	cmp	w22, #1
	b.lt	LBB3_9
; %bb.6:
	add	x19, x0, #8
Lloh50:
	adrp	x20, _assignments@GOTPAGE
Lloh51:
	ldr	x20, [x20, _assignments@GOTPAGEOFF]
Lloh52:
	adrp	x21, _error@PAGE
Lloh53:
	add	x21, x21, _error@PAGEOFF
LBB3_7:                                 ; =>This Inner Loop Header: Depth=1
	mov	x0, x19
	mov	x1, x20
	bl	_strcmp
	cbz	w0, LBB3_14
; %bb.8:                                ;   in Loop: Header=BB3_7 Depth=1
	add	x20, x20, #72
	subs	x22, x22, #1
	b.ne	LBB3_7
	b	LBB3_10
LBB3_9:
Lloh54:
	adrp	x21, _error@PAGE
Lloh55:
	add	x21, x21, _error@PAGEOFF
LBB3_10:
	ldr	w8, [x21]
	ldr	d0, [x21, #8]
	cmp	w8, #2
	b.eq	LBB3_15
LBB3_11:
	cmp	w8, #1
	b.ne	LBB3_2
; %bb.12:
	str	d0, [sp]
LBB3_13:
Lloh56:
	adrp	x0, l_.str.2@PAGE
Lloh57:
	add	x0, x0, l_.str.2@PAGEOFF
	b	LBB3_16
LBB3_14:
	add	x21, x20, #32
	ldr	w8, [x21]
	ldr	d0, [x21, #8]
	cmp	w8, #2
	b.ne	LBB3_11
LBB3_15:
	str	d0, [sp]
Lloh58:
	adrp	x0, l_.str.1@PAGE
Lloh59:
	add	x0, x0, l_.str.1@PAGEOFF
LBB3_16:
	bl	_printf
LBB3_17:
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #32]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.loh AdrpAdd	Lloh43, Lloh44
	.loh AdrpAdd	Lloh45, Lloh46
	.loh AdrpLdrGotLdr	Lloh47, Lloh48, Lloh49
	.loh AdrpAdd	Lloh52, Lloh53
	.loh AdrpLdrGot	Lloh50, Lloh51
	.loh AdrpAdd	Lloh54, Lloh55
	.loh AdrpAdd	Lloh56, Lloh57
	.loh AdrpAdd	Lloh58, Lloh59
	.cfi_endproc
	.section	__TEXT,__const
lJTI3_0:
	.byte	(LBB3_2-LBB3_2)>>2
	.byte	(LBB3_3-LBB3_2)>>2
	.byte	(LBB3_4-LBB3_2)>>2
	.byte	(LBB3_5-LBB3_2)>>2
	.byte	(LBB3_2-LBB3_2)>>2
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_VariableEval                   ; -- Begin function VariableEval
	.p2align	2
_VariableEval:                          ; @VariableEval
	.cfi_startproc
; %bb.0:
	stp	x24, x23, [sp, #-64]!           ; 16-byte Folded Spill
	stp	x22, x21, [sp, #16]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #32]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	.cfi_offset w23, -56
	.cfi_offset w24, -64
	mov	x19, x8
Lloh60:
	adrp	x8, _assignmentCnt@GOTPAGE
Lloh61:
	ldr	x8, [x8, _assignmentCnt@GOTPAGEOFF]
Lloh62:
	ldr	w23, [x8]
	cmp	w23, #1
	b.lt	LBB4_4
; %bb.1:
	mov	x20, x0
Lloh63:
	adrp	x21, _assignments@GOTPAGE
Lloh64:
	ldr	x21, [x21, _assignments@GOTPAGEOFF]
Lloh65:
	adrp	x22, _error@PAGE
Lloh66:
	add	x22, x22, _error@PAGEOFF
LBB4_2:                                 ; =>This Inner Loop Header: Depth=1
	mov	x0, x20
	mov	x1, x21
	bl	_strcmp
	cbz	w0, LBB4_5
; %bb.3:                                ;   in Loop: Header=BB4_2 Depth=1
	add	x21, x21, #72
	subs	x23, x23, #1
	b.ne	LBB4_2
	b	LBB4_6
LBB4_4:
Lloh67:
	adrp	x22, _error@PAGE
Lloh68:
	add	x22, x22, _error@PAGEOFF
	b	LBB4_6
LBB4_5:
	add	x22, x21, #32
LBB4_6:
	ldp	q0, q1, [x22]
	stp	q0, q1, [x19]
	ldr	x8, [x22, #32]
	str	x8, [x19, #32]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #32]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #16]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp], #64             ; 16-byte Folded Reload
	ret
	.loh AdrpLdrGotLdr	Lloh60, Lloh61, Lloh62
	.loh AdrpAdd	Lloh65, Lloh66
	.loh AdrpLdrGot	Lloh63, Lloh64
	.loh AdrpAdd	Lloh67, Lloh68
	.cfi_endproc
                                        ; -- End function
	.globl	_VariableAssign                 ; -- Begin function VariableAssign
	.p2align	2
_VariableAssign:                        ; @VariableAssign
	.cfi_startproc
; %bb.0:
	stp	x26, x25, [sp, #-80]!           ; 16-byte Folded Spill
	stp	x24, x23, [sp, #16]             ; 16-byte Folded Spill
	stp	x22, x21, [sp, #32]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #48]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	.cfi_offset w23, -56
	.cfi_offset w24, -64
	.cfi_offset w25, -72
	.cfi_offset w26, -80
	mov	x19, x1
	mov	x20, x0
	ldr	w8, [x1]
Lloh69:
	adrp	x23, _assignmentCnt@GOTPAGE
Lloh70:
	ldr	x23, [x23, _assignmentCnt@GOTPAGEOFF]
	cmp	w8, #3
	b.ne	LBB5_8
; %bb.1:
	ldr	w25, [x23]
	cmp	w25, #1
	b.lt	LBB5_5
; %bb.2:
	add	x21, x19, #8
Lloh71:
	adrp	x22, _assignments@GOTPAGE
Lloh72:
	ldr	x22, [x22, _assignments@GOTPAGEOFF]
Lloh73:
	adrp	x24, _error@PAGE
Lloh74:
	add	x24, x24, _error@PAGEOFF
LBB5_3:                                 ; =>This Inner Loop Header: Depth=1
	mov	x0, x21
	mov	x1, x22
	bl	_strcmp
	cbz	w0, LBB5_6
; %bb.4:                                ;   in Loop: Header=BB5_3 Depth=1
	add	x22, x22, #72
	subs	x25, x25, #1
	b.ne	LBB5_3
	b	LBB5_7
LBB5_5:
Lloh75:
	adrp	x24, _error@PAGE
Lloh76:
	add	x24, x24, _error@PAGEOFF
	b	LBB5_7
LBB5_6:
	add	x24, x22, #32
LBB5_7:
	ldp	q0, q1, [x24]
	ldr	x8, [x24, #32]
	str	x8, [x19, #32]
	stp	q0, q1, [x19]
LBB5_8:
	ldr	w22, [x23]
	cmp	w22, #1
	b.lt	LBB5_12
; %bb.9:
Lloh77:
	adrp	x21, _assignments@GOTPAGE
Lloh78:
	ldr	x21, [x21, _assignments@GOTPAGEOFF]
	mov	x24, x22
LBB5_10:                                ; =>This Inner Loop Header: Depth=1
	mov	x0, x20
	mov	x1, x21
	bl	_strcmp
	cbz	w0, LBB5_13
; %bb.11:                               ;   in Loop: Header=BB5_10 Depth=1
	add	x21, x21, #72
	subs	x24, x24, #1
	b.ne	LBB5_10
LBB5_12:
Lloh79:
	adrp	x21, _assignments@GOTPAGE
Lloh80:
	ldr	x21, [x21, _assignments@GOTPAGEOFF]
	mov	w24, #72
	smaddl	x0, w22, w24, x21
	mov	x1, x20
	mov	w2, #32
	bl	___strcpy_chk
	ldrsw	x8, [x23]
	madd	x9, x8, x24, x21
	ldr	x10, [x19, #32]
	ldp	q1, q0, [x19]
	stp	q1, q0, [x9, #32]
	str	x10, [x9, #64]
	add	w8, w8, #1
	str	w8, [x23]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #48]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #32]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #16]             ; 16-byte Folded Reload
	ldp	x26, x25, [sp], #80             ; 16-byte Folded Reload
	ret
LBB5_13:
	ldp	q0, q1, [x19]
	ldr	x8, [x19, #32]
	str	x8, [x21, #64]
	stp	q0, q1, [x21, #32]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #48]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #32]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #16]             ; 16-byte Folded Reload
	ldp	x26, x25, [sp], #80             ; 16-byte Folded Reload
	ret
	.loh AdrpLdrGot	Lloh69, Lloh70
	.loh AdrpAdd	Lloh73, Lloh74
	.loh AdrpLdrGot	Lloh71, Lloh72
	.loh AdrpAdd	Lloh75, Lloh76
	.loh AdrpLdrGot	Lloh77, Lloh78
	.loh AdrpLdrGot	Lloh79, Lloh80
	.cfi_endproc
                                        ; -- End function
	.globl	_CheckParen                     ; -- Begin function CheckParen
	.p2align	2
_CheckParen:                            ; @CheckParen
	.cfi_startproc
; %bb.0:
	stp	x22, x21, [sp, #-48]!           ; 16-byte Folded Spill
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	mov	w9, #10032
Lloh81:
	adrp	x16, ___chkstk_darwin@GOTPAGE
Lloh82:
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #2, lsl #12             ; =8192
	sub	sp, sp, #1840
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	mov	x20, x1
	mov	x19, x0
Lloh83:
	adrp	x8, ___stack_chk_guard@GOTPAGE
Lloh84:
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
Lloh85:
	ldr	x8, [x8]
	stur	x8, [x29, #-40]
	add	x21, sp, #8
	add	x0, sp, #8
	mov	w1, #10012
	bl	_bzero
	cmp	w20, #0
	b.le	LBB6_12
; %bb.1:
	mov	w9, #0
	add	x8, x19, #8
	mov	w10, #40
	mov	w11, w20
	b	LBB6_4
LBB6_2:                                 ;   in Loop: Header=BB6_4 Depth=1
	add	x9, x21, w9, sxtw
	strb	w10, [x9, #4]
	ldr	w9, [sp, #8]
	add	w9, w9, #1
	str	w9, [sp, #8]
LBB6_3:                                 ;   in Loop: Header=BB6_4 Depth=1
	add	x8, x8, #40
	subs	x11, x11, #1
	b.eq	LBB6_10
LBB6_4:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w12, [x8, #-8]
	cmp	w12, #4
	b.ne	LBB6_3
; %bb.5:                                ;   in Loop: Header=BB6_4 Depth=1
	ldrb	w12, [x8]
	cmp	w12, #40
	b.eq	LBB6_2
; %bb.6:                                ;   in Loop: Header=BB6_4 Depth=1
	cmp	w12, #41
	ccmp	w9, #0, #0, eq
	b.eq	LBB6_11
; %bb.7:                                ;   in Loop: Header=BB6_4 Depth=1
	cmp	w12, #41
	b.ne	LBB6_3
; %bb.8:                                ;   in Loop: Header=BB6_4 Depth=1
	sxtw	x12, w9
	sub	x12, x12, #1
	add	x13, x21, x12
	ldrb	w13, [x13, #4]
	cmp	w13, #40
	b.ne	LBB6_3
; %bb.9:                                ;   in Loop: Header=BB6_4 Depth=1
	str	w12, [sp, #8]
	mov	x9, x12
	b	LBB6_3
LBB6_10:
	cbz	w9, LBB6_16
LBB6_11:
	mov	w0, #-1
	b	LBB6_27
LBB6_12:
	sub	w8, w20, #1
LBB6_13:
	ldrb	w9, [x19, #8]
	cmp	w9, #40
	b.ne	LBB6_26
; %bb.14:
	smaddl	x8, w8, w9, x19
	ldrb	w8, [x8, #8]
	cmp	w8, #41
	b.ne	LBB6_26
; %bb.15:
	mov	w0, #1
	b	LBB6_27
LBB6_16:
	sub	w8, w20, #1
	cmp	w20, #3
	b.lt	LBB6_13
; %bb.17:
	mov	w9, #0
	add	x10, x19, #48
	sub	x11, x8, #1
	add	x12, sp, #8
	mov	w13, #40
	b	LBB6_21
LBB6_18:                                ;   in Loop: Header=BB6_21 Depth=1
	sxtw	x14, w9
	sub	x14, x14, #1
	add	x15, x12, x14
	ldrb	w15, [x15, #4]
	cmp	w15, #40
	csel	w9, w14, w9, eq
LBB6_19:                                ;   in Loop: Header=BB6_21 Depth=1
	str	w9, [sp, #8]
LBB6_20:                                ;   in Loop: Header=BB6_21 Depth=1
	add	x10, x10, #40
	subs	x11, x11, #1
	b.eq	LBB6_25
LBB6_21:                                ; =>This Inner Loop Header: Depth=1
	ldur	w14, [x10, #-8]
	cmp	w14, #4
	b.ne	LBB6_20
; %bb.22:                               ;   in Loop: Header=BB6_21 Depth=1
	ldrb	w14, [x10]
	cmp	w14, #41
	b.eq	LBB6_18
; %bb.23:                               ;   in Loop: Header=BB6_21 Depth=1
	cmp	w14, #40
	b.ne	LBB6_20
; %bb.24:                               ;   in Loop: Header=BB6_21 Depth=1
	add	x9, x12, w9, sxtw
	strb	w13, [x9, #4]
	ldr	w9, [sp, #8]
	add	w9, w9, #1
	b	LBB6_19
LBB6_25:
	cbz	w9, LBB6_13
LBB6_26:
	mov	w0, #0
LBB6_27:
	ldur	x8, [x29, #-40]
Lloh86:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh87:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh88:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB6_29
; %bb.28:
	add	sp, sp, #2, lsl #12             ; =8192
	add	sp, sp, #1840
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp], #48             ; 16-byte Folded Reload
	ret
LBB6_29:
	bl	___stack_chk_fail
	.loh AdrpLdrGotLdr	Lloh83, Lloh84, Lloh85
	.loh AdrpLdrGot	Lloh81, Lloh82
	.loh AdrpLdrGotLdr	Lloh86, Lloh87, Lloh88
	.cfi_endproc
                                        ; -- End function
	.globl	_MainOperator                   ; -- Begin function MainOperator
	.p2align	2
_MainOperator:                          ; @MainOperator
	.cfi_startproc
; %bb.0:
	stp	x22, x21, [sp, #-48]!           ; 16-byte Folded Spill
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	mov	w9, #10032
Lloh89:
	adrp	x16, ___chkstk_darwin@GOTPAGE
Lloh90:
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #2, lsl #12             ; =8192
	sub	sp, sp, #1840
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	mov	x20, x1
	mov	x19, x0
Lloh91:
	adrp	x8, ___stack_chk_guard@GOTPAGE
Lloh92:
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
Lloh93:
	ldr	x8, [x8]
	stur	x8, [x29, #-40]
	add	x21, sp, #8
	add	x0, sp, #8
	mov	w1, #10012
	bl	_bzero
	cmp	w20, #1
	b.lt	LBB7_25
; %bb.1:
	mov	w1, #0
	mov	w2, #0
	mov	x8, #0
	mov	w12, #0
	mov	x0, #0
	mov	x10, #-4294967296
	mov	w11, #1
	mov	x13, #1
	movk	x13, #33792, lsl #32
	mov	x14, #190215511605248
	movk	x14, #8192, lsl #48
	mov	w15, #40
	mov	x16, #4294967296
	mov	x9, x19
	mov	w17, w20
	b	LBB7_5
LBB7_2:                                 ;   in Loop: Header=BB7_5 Depth=1
	add	x1, x21, w2, sxtw
	strb	w15, [x1, #4]
	ldr	w1, [sp, #8]
	add	w1, w1, #1
	str	w1, [sp, #8]
LBB7_3:                                 ;   in Loop: Header=BB7_5 Depth=1
	mov	x2, x1
LBB7_4:                                 ;   in Loop: Header=BB7_5 Depth=1
	add	x8, x8, #1
	add	x10, x10, x16
	add	x9, x9, #40
	cmp	x17, x8
	b.eq	LBB7_26
LBB7_5:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w3, [x9]
	cmp	w3, #4
	b.ne	LBB7_4
; %bb.6:                                ;   in Loop: Header=BB7_5 Depth=1
	ldrb	w3, [x9, #8]
	cmp	w3, #41
	b.eq	LBB7_8
; %bb.7:                                ;   in Loop: Header=BB7_5 Depth=1
	cmp	w3, #40
	b.eq	LBB7_2
	b	LBB7_10
LBB7_8:                                 ;   in Loop: Header=BB7_5 Depth=1
	sxtw	x2, w2
	sub	x2, x2, #1
	add	x4, x21, x2
	ldrb	w4, [x4, #4]
	cmp	w4, #40
	b.ne	LBB7_10
; %bb.9:                                ;   in Loop: Header=BB7_5 Depth=1
	str	w2, [sp, #8]
	mov	x1, x2
                                        ; kill: def $w2 killed $w2 killed $x2 def $x2
	b	LBB7_4
LBB7_10:                                ;   in Loop: Header=BB7_5 Depth=1
	cbnz	w1, LBB7_3
; %bb.11:                               ;   in Loop: Header=BB7_5 Depth=1
	cmp	w3, #43
	b.eq	LBB7_19
; %bb.12:                               ;   in Loop: Header=BB7_5 Depth=1
	cmp	w3, #61
	b.eq	LBB7_28
; %bb.13:                               ;   in Loop: Header=BB7_5 Depth=1
	cmp	w3, #45
	b.ne	LBB7_20
; %bb.14:                               ;   in Loop: Header=BB7_5 Depth=1
	cbz	x8, LBB7_20
; %bb.15:                               ;   in Loop: Header=BB7_5 Depth=1
	ldur	w1, [x9, #-40]
	cmp	w1, #4
	b.ne	LBB7_18
; %bb.16:                               ;   in Loop: Header=BB7_5 Depth=1
	ldurb	w1, [x9, #-32]
	cmp	w1, #61
	b.hi	LBB7_18
; %bb.17:                               ;   in Loop: Header=BB7_5 Depth=1
	lsl	x1, x11, x1
	tst	x1, x14
	b.ne	LBB7_24
LBB7_18:                                ;   in Loop: Header=BB7_5 Depth=1
	mov	w1, #0
	mov	w2, #0
	mov	w12, #45
	mov	x0, x9
	b	LBB7_4
LBB7_19:                                ;   in Loop: Header=BB7_5 Depth=1
	mov	w1, #0
	mov	w2, #0
	mov	x0, x9
	mov	x12, x3
	b	LBB7_4
LBB7_20:                                ;   in Loop: Header=BB7_5 Depth=1
	cmp	w3, #47
	b.eq	LBB7_22
; %bb.21:                               ;   in Loop: Header=BB7_5 Depth=1
	cmp	w3, #42
	b.ne	LBB7_24
LBB7_22:                                ;   in Loop: Header=BB7_5 Depth=1
	cmp	w12, #47
	b.hi	LBB7_24
; %bb.23:                               ;   in Loop: Header=BB7_5 Depth=1
	mov	w1, w12
	lsl	x1, x11, x1
	tst	x1, x13
	csel	w1, wzr, wzr, ne
	csel	w2, wzr, wzr, ne
	csel	x0, x9, x0, ne
	csel	w12, w3, w12, ne
	b	LBB7_4
LBB7_24:                                ;   in Loop: Header=BB7_5 Depth=1
	mov	w1, #0
	mov	w2, #0
	b	LBB7_4
LBB7_25:
	mov	x0, #0
LBB7_26:
	ldur	x8, [x29, #-40]
Lloh94:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh95:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh96:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB7_29
LBB7_27:
	add	sp, sp, #2, lsl #12             ; =8192
	add	sp, sp, #1840
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp], #48             ; 16-byte Folded Reload
	ret
LBB7_28:
	asr	x10, x10, #32
	mov	w11, #40
	mul	x10, x10, x11
	ldr	w10, [x19, x10]
	cmp	w8, #1
	ccmp	w10, #3, #0, eq
Lloh97:
	adrp	x8, _ptrError@PAGE
Lloh98:
	ldr	x8, [x8, _ptrError@PAGEOFF]
	csel	x0, x9, x8, eq
	ldur	x8, [x29, #-40]
Lloh99:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh100:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh101:
	ldr	x9, [x9]
	cmp	x9, x8
	b.eq	LBB7_27
LBB7_29:
	bl	___stack_chk_fail
	.loh AdrpLdrGotLdr	Lloh91, Lloh92, Lloh93
	.loh AdrpLdrGot	Lloh89, Lloh90
	.loh AdrpLdrGotLdr	Lloh94, Lloh95, Lloh96
	.loh AdrpLdrGotLdr	Lloh99, Lloh100, Lloh101
	.loh AdrpLdr	Lloh97, Lloh98
	.cfi_endproc
                                        ; -- End function
	.globl	_MinusSupport                   ; -- Begin function MinusSupport
	.p2align	2
_MinusSupport:                          ; @MinusSupport
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-48]!           ; 16-byte Folded Spill
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	mov	w9, #10032
Lloh102:
	adrp	x16, ___chkstk_darwin@GOTPAGE
Lloh103:
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #2, lsl #12             ; =8192
	sub	sp, sp, #1840
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w27, -40
	.cfi_offset w28, -48
	mov	x20, x1
	mov	x19, x0
Lloh104:
	adrp	x8, ___stack_chk_guard@GOTPAGE
Lloh105:
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
Lloh106:
	ldr	x8, [x8]
	stur	x8, [x29, #-40]
	add	x0, sp, #8
	mov	w1, #10012
	bl	_bzero
	ldr	w13, [x19]
	cmp	w13, #4
	b.ne	LBB8_2
; %bb.1:
	ldrb	w8, [x19, #8]
	cmp	w8, #45
	ccmp	w20, #1, #4, eq
	b.gt	LBB8_16
LBB8_2:
	cmp	w20, #2
	b.lt	LBB8_15
; %bb.3:
	mov	w11, #0
	mov	w12, #0
	sub	w8, w20, #1
	add	x19, x19, #40
	sub	x8, x8, #1
	add	x9, sp, #8
	mov	w10, #40
	cmp	w13, #4
	b.ne	LBB8_13
LBB8_4:
	ldurb	w13, [x19, #-32]
	cmp	w13, #40
	b.eq	LBB8_7
; %bb.5:
	cmp	w13, #41
	b.ne	LBB8_9
; %bb.6:
	sxtw	x11, w12
	sub	x11, x11, #1
	add	x13, x9, x11
	ldrb	w13, [x13, #4]
	cmp	w13, #40
	csel	w11, w11, w12, eq
	b	LBB8_8
LBB8_7:
	add	x11, x9, w12, sxtw
	strb	w10, [x11, #4]
	ldr	w11, [sp, #8]
	add	w11, w11, #1
LBB8_8:
	str	w11, [sp, #8]
	mov	x12, x11
	b	LBB8_13
LBB8_9:
	mov	x12, x11
	cbnz	w11, LBB8_13
; %bb.10:
	ldr	w11, [x19]
	cmp	w11, #4
	b.ne	LBB8_12
; %bb.11:
	ldrb	w11, [x19, #8]
	cmp	w11, #45
	b.eq	LBB8_16
LBB8_12:
	mov	w11, #0
	mov	w12, #0
LBB8_13:                                ; =>This Inner Loop Header: Depth=1
	cbz	x8, LBB8_15
; %bb.14:                               ;   in Loop: Header=BB8_13 Depth=1
	ldr	w13, [x19], #40
	sub	x8, x8, #1
	cmp	w13, #4
	b.eq	LBB8_4
	b	LBB8_13
LBB8_15:
	mov	x19, #0
LBB8_16:
	ldur	x8, [x29, #-40]
Lloh107:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh108:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh109:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB8_18
; %bb.17:
	mov	x0, x19
	add	sp, sp, #2, lsl #12             ; =8192
	add	sp, sp, #1840
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #48             ; 16-byte Folded Reload
	ret
LBB8_18:
	bl	___stack_chk_fail
	.loh AdrpLdrGotLdr	Lloh104, Lloh105, Lloh106
	.loh AdrpLdrGot	Lloh102, Lloh103
	.loh AdrpLdrGotLdr	Lloh107, Lloh108, Lloh109
	.cfi_endproc
                                        ; -- End function
	.globl	_BinaryEval                     ; -- Begin function BinaryEval
	.p2align	2
_BinaryEval:                            ; @BinaryEval
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #128
	stp	x26, x25, [sp, #48]             ; 16-byte Folded Spill
	stp	x24, x23, [sp, #64]             ; 16-byte Folded Spill
	stp	x22, x21, [sp, #80]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #96]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #112]            ; 16-byte Folded Spill
	add	x29, sp, #112
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	.cfi_offset w23, -56
	.cfi_offset w24, -64
	.cfi_offset w25, -72
	.cfi_offset w26, -80
	mov	x22, x2
	mov	x20, x1
	mov	x21, x0
	mov	x19, x8
Lloh110:
	adrp	x8, ___stack_chk_guard@GOTPAGE
Lloh111:
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
Lloh112:
	ldr	x8, [x8]
	str	x8, [sp, #40]
	ldr	w8, [x1]
	cmp	w8, #3
	b.ne	LBB9_8
; %bb.1:
Lloh113:
	adrp	x8, _assignmentCnt@GOTPAGE
Lloh114:
	ldr	x8, [x8, _assignmentCnt@GOTPAGEOFF]
Lloh115:
	ldr	w26, [x8]
	cmp	w26, #1
	b.lt	LBB9_5
; %bb.2:
	add	x23, x20, #8
Lloh116:
	adrp	x24, _assignments@GOTPAGE
Lloh117:
	ldr	x24, [x24, _assignments@GOTPAGEOFF]
Lloh118:
	adrp	x25, _error@PAGE
Lloh119:
	add	x25, x25, _error@PAGEOFF
LBB9_3:                                 ; =>This Inner Loop Header: Depth=1
	mov	x0, x23
	mov	x1, x24
	bl	_strcmp
	cbz	w0, LBB9_6
; %bb.4:                                ;   in Loop: Header=BB9_3 Depth=1
	add	x24, x24, #72
	subs	x26, x26, #1
	b.ne	LBB9_3
	b	LBB9_7
LBB9_5:
Lloh120:
	adrp	x25, _error@PAGE
Lloh121:
	add	x25, x25, _error@PAGEOFF
	b	LBB9_7
LBB9_6:
	add	x25, x24, #32
LBB9_7:
	ldp	q0, q1, [x25]
	ldr	x8, [x25, #32]
	str	x8, [x20, #32]
	stp	q0, q1, [x20]
LBB9_8:
	ldr	w8, [x21]
	cmp	w8, #0
	ccmp	w8, #4, #4, ne
	b.eq	LBB9_10
; %bb.9:
	ldr	w9, [x20]
	orr	w9, w9, #0x4
	cmp	w9, #4
	b.ne	LBB9_13
LBB9_10:
Lloh122:
	adrp	x8, _error@PAGE
Lloh123:
	add	x8, x8, _error@PAGEOFF
	ldp	q0, q1, [x8]
	stp	q0, q1, [x19]
	ldr	x8, [x8, #32]
LBB9_11:
	str	x8, [x19, #32]
	ldr	x8, [sp, #40]
Lloh124:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh125:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh126:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB9_55
LBB9_12:
	ldp	x29, x30, [sp, #112]            ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #96]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #80]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #64]             ; 16-byte Folded Reload
	ldp	x26, x25, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #128
	ret
LBB9_13:
	cmp	w22, #61
	b.ne	LBB9_16
; %bb.14:
	cmp	w8, #3
	b.ne	LBB9_16
; %bb.15:
	add	x0, x21, #8
	ldp	q0, q1, [x20]
	stp	q0, q1, [sp]
	ldr	x8, [x20, #32]
	str	x8, [sp, #32]
	mov	x1, sp
	bl	_VariableAssign
	ldp	q0, q1, [x20]
	stp	q0, q1, [x19]
	ldr	x8, [x20, #32]
	b	LBB9_11
LBB9_16:
	cmp	w8, #3
	b.ne	LBB9_24
; %bb.17:
Lloh127:
	adrp	x8, _assignmentCnt@GOTPAGE
Lloh128:
	ldr	x8, [x8, _assignmentCnt@GOTPAGEOFF]
Lloh129:
	ldr	w26, [x8]
	cmp	w26, #1
	b.lt	LBB9_21
; %bb.18:
	add	x23, x21, #8
Lloh130:
	adrp	x24, _assignments@GOTPAGE
Lloh131:
	ldr	x24, [x24, _assignments@GOTPAGEOFF]
Lloh132:
	adrp	x25, _error@PAGE
Lloh133:
	add	x25, x25, _error@PAGEOFF
LBB9_19:                                ; =>This Inner Loop Header: Depth=1
	mov	x0, x23
	mov	x1, x24
	bl	_strcmp
	cbz	w0, LBB9_22
; %bb.20:                               ;   in Loop: Header=BB9_19 Depth=1
	add	x24, x24, #72
	subs	x26, x26, #1
	b.ne	LBB9_19
	b	LBB9_23
LBB9_21:
Lloh134:
	adrp	x25, _error@PAGE
Lloh135:
	add	x25, x25, _error@PAGEOFF
	b	LBB9_23
LBB9_22:
	add	x25, x24, #32
LBB9_23:
	ldr	x8, [x25, #32]
	ldp	q1, q0, [x25]
	str	x8, [x21, #32]
	stp	q1, q0, [x21]
	ldr	w8, [x21]
LBB9_24:
	cbz	w8, LBB9_10
; %bb.25:
	cmp	w8, #4
	b.eq	LBB9_10
; %bb.26:
	ldr	w9, [x20]
	orr	w10, w9, #0x4
	cmp	w10, #4
	b.eq	LBB9_10
; %bb.27:
	cmp	w8, w9
	b.ne	LBB9_33
; %bb.28:
	movi	d0, #0000000000000000
	cmp	w9, #2
	b.eq	LBB9_40
; %bb.29:
	cmp	w9, #1
	b.ne	LBB9_43
; %bb.30:
	mov	w8, #1
	sub	w9, w22, #42
	cmp	w9, #5
	b.hi	LBB9_54
; %bb.31:
Lloh136:
	adrp	x10, lJTI9_2@PAGE
Lloh137:
	add	x10, x10, lJTI9_2@PAGEOFF
	adr	x11, LBB9_32
	ldrb	w12, [x10, x9]
	add	x11, x11, x12, lsl #2
	br	x11
LBB9_32:
	ldr	w8, [x21, #8]
	ldr	w9, [x20, #8]
	mul	w8, w9, w8
	b	LBB9_50
LBB9_33:
	cmp	w8, #1
	b.ne	LBB9_35
; %bb.34:
	ldr	s0, [x21, #8]
	sshll.2d	v0, v0, #0
	scvtf	d1, d0
	ldr	d2, [x20, #8]
	b	LBB9_37
LBB9_35:
	movi	d1, #0000000000000000
	movi	d2, #0000000000000000
	cmp	w9, #1
	b.ne	LBB9_37
; %bb.36:
	ldr	d1, [x21, #8]
	ldr	s0, [x20, #8]
	sshll.2d	v0, v0, #0
	scvtf	d2, d0
LBB9_37:
	mov	w8, #2
	movi	d0, #0000000000000000
	sub	w9, w22, #42
	cmp	w9, #5
	b.hi	LBB9_54
; %bb.38:
Lloh138:
	adrp	x10, lJTI9_0@PAGE
Lloh139:
	add	x10, x10, lJTI9_0@PAGEOFF
	adr	x11, LBB9_39
	ldrb	w12, [x10, x9]
	add	x11, x11, x12, lsl #2
	br	x11
LBB9_39:
	fmul	d0, d1, d2
	mov	w8, #2
	b	LBB9_54
LBB9_40:
	mov	w8, #2
	sub	w9, w22, #42
	cmp	w9, #5
	b.hi	LBB9_54
; %bb.41:
Lloh140:
	adrp	x10, lJTI9_1@PAGE
Lloh141:
	add	x10, x10, lJTI9_1@PAGEOFF
	adr	x11, LBB9_42
	ldrb	w12, [x10, x9]
	add	x11, x11, x12, lsl #2
	br	x11
LBB9_42:
	ldr	d0, [x21, #8]
	ldr	d1, [x20, #8]
	fmul	d0, d0, d1
	mov	w8, #2
	b	LBB9_54
LBB9_43:
	mov	w8, #0
	b	LBB9_54
LBB9_44:
	fadd	d0, d1, d2
	mov	w8, #2
	b	LBB9_54
LBB9_45:
	fsub	d0, d1, d2
	mov	w8, #2
	b	LBB9_54
LBB9_46:
	mov	w8, #2
	fdiv	d0, d1, d2
	b	LBB9_54
LBB9_47:
	ldr	w8, [x21, #8]
	ldr	w9, [x20, #8]
	add	w8, w9, w8
	b	LBB9_50
LBB9_48:
	ldr	w8, [x21, #8]
	ldr	w9, [x20, #8]
	sub	w8, w8, w9
	b	LBB9_50
LBB9_49:
	ldr	w8, [x20, #8]
	ldr	w9, [x21, #8]
	sdiv	w8, w9, w8
LBB9_50:
	fmov	d0, x8
	mov	w8, #1
	b	LBB9_54
LBB9_51:
	ldr	d0, [x21, #8]
	ldr	d1, [x20, #8]
	fadd	d0, d0, d1
	mov	w8, #2
	b	LBB9_54
LBB9_52:
	ldr	d0, [x21, #8]
	ldr	d1, [x20, #8]
	fsub	d0, d0, d1
	mov	w8, #2
	b	LBB9_54
LBB9_53:
	ldr	d0, [x21, #8]
	ldr	d1, [x20, #8]
	mov	w8, #2
	fdiv	d0, d0, d1
LBB9_54:
	stp	w8, wzr, [x19]
	str	d0, [x19, #8]
	stp	xzr, xzr, [x19, #24]
	str	xzr, [x19, #16]
	ldr	x8, [sp, #40]
Lloh142:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh143:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh144:
	ldr	x9, [x9]
	cmp	x9, x8
	b.eq	LBB9_12
LBB9_55:
	bl	___stack_chk_fail
	.loh AdrpLdrGotLdr	Lloh110, Lloh111, Lloh112
	.loh AdrpLdrGotLdr	Lloh113, Lloh114, Lloh115
	.loh AdrpAdd	Lloh118, Lloh119
	.loh AdrpLdrGot	Lloh116, Lloh117
	.loh AdrpAdd	Lloh120, Lloh121
	.loh AdrpAdd	Lloh122, Lloh123
	.loh AdrpLdrGotLdr	Lloh124, Lloh125, Lloh126
	.loh AdrpLdrGotLdr	Lloh127, Lloh128, Lloh129
	.loh AdrpAdd	Lloh132, Lloh133
	.loh AdrpLdrGot	Lloh130, Lloh131
	.loh AdrpAdd	Lloh134, Lloh135
	.loh AdrpAdd	Lloh136, Lloh137
	.loh AdrpAdd	Lloh138, Lloh139
	.loh AdrpAdd	Lloh140, Lloh141
	.loh AdrpLdrGotLdr	Lloh142, Lloh143, Lloh144
	.cfi_endproc
	.section	__TEXT,__const
lJTI9_0:
	.byte	(LBB9_39-LBB9_39)>>2
	.byte	(LBB9_44-LBB9_39)>>2
	.byte	(LBB9_54-LBB9_39)>>2
	.byte	(LBB9_45-LBB9_39)>>2
	.byte	(LBB9_54-LBB9_39)>>2
	.byte	(LBB9_46-LBB9_39)>>2
lJTI9_1:
	.byte	(LBB9_42-LBB9_42)>>2
	.byte	(LBB9_51-LBB9_42)>>2
	.byte	(LBB9_54-LBB9_42)>>2
	.byte	(LBB9_52-LBB9_42)>>2
	.byte	(LBB9_54-LBB9_42)>>2
	.byte	(LBB9_53-LBB9_42)>>2
lJTI9_2:
	.byte	(LBB9_32-LBB9_32)>>2
	.byte	(LBB9_47-LBB9_32)>>2
	.byte	(LBB9_54-LBB9_32)>>2
	.byte	(LBB9_48-LBB9_32)>>2
	.byte	(LBB9_54-LBB9_32)>>2
	.byte	(LBB9_49-LBB9_32)>>2
                                        ; -- End function
	.globl	_error                          ; @error
.zerofill __DATA,__common,_error,40,3
	.section	__DATA,__data
	.globl	_ptrError                       ; @ptrError
	.p2align	3
_ptrError:
	.quad	_error

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%s"

	.comm	_assignmentCnt,4,2              ; @assignmentCnt
	.comm	_assignments,720360,3           ; @assignments
l_.str.1:                               ; @.str.1
	.asciz	"%f\n"

l_.str.2:                               ; @.str.2
	.asciz	"%d\n"

l_.str.4:                               ; @.str.4
	.asciz	"+"

l_.str.5:                               ; @.str.5
	.asciz	"-"

l_.str.6:                               ; @.str.6
	.asciz	"*"

l_.str.7:                               ; @.str.7
	.asciz	"/"

l_.str.8:                               ; @.str.8
	.asciz	"="

l_.str.9:                               ; @.str.9
	.asciz	"("

l_.str.10:                              ; @.str.10
	.asciz	")"

l_.str.11:                              ; @.str.11
	.asciz	"%lf"

l_.str.12:                              ; @.str.12
	.asciz	"%d"

l_str.13:                               ; @str.13
	.asciz	"Error"

.subsections_via_symbols
