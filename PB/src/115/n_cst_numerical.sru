HA$PBExportHeader$n_cst_numerical.sru
forward
global type n_cst_numerical from nonvisualobject
end type
end forward

global type n_cst_numerical from nonvisualobject autoinstantiate
end type

forward prototypes
public function string of_binary (long al_decimal)
public function long of_decimal (string as_binary)
public function boolean of_getbit (long al_decimal, unsignedinteger aui_bit)
public function long of_bitwiseand (long al_decimala, long al_decimalb)
public function long of_bitwiseor (long al_decimala, long al_decimalb)
public function long of_setbit (long al_decimal, unsignedinteger aui_bit)
public function long of_clearbit (long al_decimal, unsignedinteger aui_bit)
public function long of_flipbit (long al_decimal, unsignedinteger aui_bit)
public function long of_bitwisenot (long al_decimal)
public function long of_bitwisexor (long al_decimala, long al_decimalb)
public function integer of_bitwiseand (integer ai_decimala, integer ai_decimalb)
public function integer of_bitwiseor (integer ai_decimala, integer ai_decimalb)
public function int of_setbit (int ai_decimal, unsignedinteger aui_bit)
public function int of_clearbit (int ai_decimal, unsignedinteger aui_bit)
public function int of_flipbit (int ai_decimal, unsignedinteger aui_bit)
public function integer of_bitwisenot (integer ai_decimal)
public function integer of_bitwisexor (integer ai_decimala, integer ai_decimalb)
end prototypes

public function string of_binary (long al_decimal);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_Binary
//
// Access:	public
//
//	Arguments:
//		al_decimal		unsigned long to convert to bit string
//
//	Returns:  string
//
//	Description:	Convert al_decimal to a string of 32 1's and 0's in
//						big-endian format i.e with LSB at position 1.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

string 			ls_binary
unsignedint 	lui_cnt
long 				ll_remainder
unsignedlong	lul_decimal

lul_decimal = al_decimal

for lui_cnt = 1 to 32
	ll_remainder = mod(lul_decimal, 2)
	lul_decimal = lul_decimal / 2

	ls_binary = ls_binary + string(ll_remainder)
next

return ls_binary
end function

public function long of_decimal (string as_binary);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_Decimal
//
// Access:	public
//
//	Arguments:
//		as_binary	string to convert
//
//	Returns:	long
//
//	Description:	Convert an array of 1's and 0's in big-endian format
//						i.e. LSB at index 1 to a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

long ll_decimal
unsignedint lui_cnt

// Propogate the sign bit
as_binary += Fill(Right(as_binary, 1), 31)

// Calculate the value
for lui_cnt = 1 to 32
	ll_decimal = ll_decimal + (long(Mid(as_binary, lui_cnt, 1)) * (2 ^ (lui_cnt - 1)))
next

return ll_decimal
end function

public function boolean of_getbit (long al_decimal, unsignedinteger aui_bit);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_GetBit
//
// Access:	public
//
//	Arguments:
//		al_decimal		value
//		aui_bit			bit number to test
//
//	Returns:  boolean
//
//	Description:	Tests a given bit in a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedlong	lul_decimal

lul_decimal	= al_decimal

if (Mod(long(lul_decimal /  2 ^(aui_bit - 1)), 2) > 0) then
	return true
end if

return false
end function

public function long of_bitwiseand (long al_decimala, long al_decimalb);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseAND
//
// Access:	public
//
//	Arguments:
//		al_decimala
//		al_decimalb
//
//	Returns:  long
//
//	Description:	Logically AND 2 numbers
//
//		a	b	result
//		-- -- ------
//		0	0	0
//		0	1	0
//		1	0	0
//		1	1	1
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
long			ll_decimal

ll_decimal = 0

for lui_bit = 1 to 32
	if this.of_GetBit(al_decimala, lui_bit) and this.of_GetBit(al_decimalb, lui_bit) then
		ll_decimal = this.of_SetBit(ll_decimal, lui_bit)
	end if
next

return ll_decimal
end function

public function long of_bitwiseor (long al_decimala, long al_decimalb);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseOR
//
// Access:	public
//
//	Arguments:
//		al_decimala
//		al_decimalb
//
//	Returns:  long
//
//	Description:	Logically OR 2 numbers
//
//		a	b	result
//		-- -- ------
//		0	0	0
//		0	1	1
//		1	0	1
//		1	1	1
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
long			ll_decimal

ll_decimal = 0

for lui_bit = 1 to 32
	if this.of_GetBit(al_decimala, lui_bit) or this.of_GetBit(al_decimalb, lui_bit) then
		ll_decimal = this.of_SetBit(ll_decimal, lui_bit)
	end if
next

return ll_decimal
end function

public function long of_setbit (long al_decimal, unsignedinteger aui_bit);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_SetBit
//
// Access:	public
//
//	Arguments:
//		al_decimal		value
//		aui_bit			bit number to set
//
//	Returns:  new value
//
//	Description:	Sets a given bit in a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

if not this.of_GetBit(al_decimal, aui_bit) then
	return al_decimal + (2 ^ (aui_bit - 1))
end if

return al_decimal
end function

public function long of_clearbit (long al_decimal, unsignedinteger aui_bit);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_ClearBit
//
// Access:	public
//
//	Arguments:
//		al_decimal		value
//		aui_bit			bit number to clear
//
//	Returns:  new value
//
//	Description:	Clears a given bit in a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

if of_GetBit(al_decimal, aui_bit) then
	return al_decimal - (2 ^ (aui_bit - 1))
end if

return al_decimal
end function

public function long of_flipbit (long al_decimal, unsignedinteger aui_bit);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_FlipBit
//
// Access:	public
//
//	Arguments:
//		al_decimal		value
//		aui_bit			bit number to flip
//
//	Returns:  new value
//
//	Description:	Flips a given bit in a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

if not this.of_GetBit(al_decimal, aui_bit) then
	return this.of_SetBit(al_decimal, aui_bit)
else
	return this.of_ClearBit(al_decimal, aui_bit)
end if
end function

public function long of_bitwisenot (long al_decimal);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseNOT
//
// Access:	public
//
//	Arguments:
//		al_decimal		value to not
//
//	Returns:	none
//
//	Description:	Logically NOT all bits in a number
//
//		a	result
//		-- ------
//		0	1
//		1	0
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
long			ll_decimal

ll_decimal = 0

for lui_bit = 1 to 32
	if not this.of_GetBit(al_decimal, lui_bit) then
		ll_decimal = this.of_SetBit(ll_decimal, lui_bit)
	end if
next

return ll_decimal
end function

public function long of_bitwisexor (long al_decimala, long al_decimalb);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseXOR
//
// Access:	public
//
//	Arguments:
//		al_decimala
//		al_decimalb
//
//	Returns:  long
//
//	Description:	Logically XOR 2 numbers
//
//		a	b	result
//		-- -- ------
//		0	0	0
//		0	1	1
//		1	0	1
//		1	1	0
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
long			ll_decimal

ll_decimal = 0

for lui_bit = 1 to 32
	if this.of_GetBit(al_decimala, lui_bit) <> this.of_GetBit(al_decimalb, lui_bit) then
		ll_decimal += (2 ^ (lui_bit - 1))
	end if
next

return ll_decimal
end function

public function integer of_bitwiseand (integer ai_decimala, integer ai_decimalb);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseAND
//
// Access:	public
//
//	Arguments:
//		ai_decimala
//		ai_decimalb
//
//	Returns:  int
//
//	Description:	Logically AND 2 numbers
//
//		a	b	result
//		-- -- ------
//		0	0	0
//		0	1	0
//		1	0	0
//		1	1	1
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
int			li_decimal

li_decimal = 0

for lui_bit = 1 to 16
	if this.of_GetBit(ai_decimala, lui_bit) and this.of_GetBit(ai_decimalb, lui_bit) then
		li_decimal = this.of_SetBit(li_decimal, lui_bit)
	end if
next

return li_decimal
end function

public function integer of_bitwiseor (integer ai_decimala, integer ai_decimalb);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseOR
//
// Access:	public
//
//	Arguments:
//		ai_decimala
//		ai_decimalb
//
//	Returns:  int
//
//	Description:	Logically OR 2 numbers
//
//		a	b	result
//		-- -- ------
//		0	0	0
//		0	1	1
//		1	0	1
//		1	1	1
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
int			li_decimal

li_decimal = 0

for lui_bit = 1 to 16
	if this.of_GetBit(ai_decimala, lui_bit) or this.of_GetBit(ai_decimalb, lui_bit) then
		li_decimal = this.of_SetBit(li_decimal, lui_bit)
	end if
next

return li_decimal
end function

public function int of_setbit (int ai_decimal, unsignedinteger aui_bit);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_SetBit
//
// Access:	public
//
//	Arguments:
//		ai_decimal		value
//		aui_bit			bit number to set
//
//	Returns:  new value
//
//	Description:	Sets a given bit in a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

if not this.of_GetBit(ai_decimal, aui_bit) then
	return ai_decimal + (2 ^ (aui_bit - 1))
end if

return ai_decimal
end function

public function int of_clearbit (int ai_decimal, unsignedinteger aui_bit);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_ClearBit
//
// Access:	public
//
//	Arguments:
//		ai_decimal		value
//		aui_bit			bit number to clear
//
//	Returns:  new value
//
//	Description:	Clears a given bit in a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

if of_GetBit(ai_decimal, aui_bit) then
	return ai_decimal - (2 ^ (aui_bit - 1))
end if

return ai_decimal
end function

public function int of_flipbit (int ai_decimal, unsignedinteger aui_bit);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_FlipBit
//
// Access:	public
//
//	Arguments:
//		ai_decimal		value
//		aui_bit			bit number to flip
//
//	Returns:  new value
//
//	Description:	Flips a given bit in a number.
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

if not this.of_GetBit(ai_decimal, aui_bit) then
	return this.of_SetBit(ai_decimal, aui_bit)
else
	return this.of_ClearBit(ai_decimal, aui_bit)
end if
end function

public function integer of_bitwisenot (integer ai_decimal);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseNOT
//
// Access:	public
//
//	Arguments:
//		ai_decimal		value to not
//
//	Returns:	none
//
//	Description:	Logically NOT all bits in a number
//
//		a	result
//		-- ------
//		0	1
//		1	0
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
int			li_decimal

li_decimal = 0

for lui_bit = 1 to 16
	if not this.of_GetBit(ai_decimal, lui_bit) then
		li_decimal = this.of_SetBit(li_decimal, lui_bit)
	end if
next

return li_decimal
end function

public function integer of_bitwisexor (integer ai_decimala, integer ai_decimalb);//////////////////////////////////////////////////////////////////////////////
//
//	Function:  of_BitwiseXOR
//
// Access:	public
//
//	Arguments:
//		ai_decimala
//		ai_decimalb
//
//	Returns:  int
//
//	Description:	Logically XOR 2 numbers
//
//		a	b	result
//		-- -- ------
//		0	0	0
//		0	1	1
//		1	0	1
//		1	1	0
//
//////////////////////////////////////////////////////////////////////////////
//	
//	Revision History
//
//	Version
//	1.0   Initial version
//
//////////////////////////////////////////////////////////////////////////////
//
//	Copyright $$HEX2$$a9002000$$ENDHEX$$1996 Simon Harris (simon@addease.com.au).  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

unsignedint lui_bit
int			li_decimal

li_decimal = 0

for lui_bit = 1 to 16
	if this.of_GetBit(ai_decimala, lui_bit) <> this.of_GetBit(ai_decimalb, lui_bit) then
		li_decimal = this.of_SetBit(li_decimal, lui_bit)
	end if
next

return li_decimal
end function

on n_cst_numerical.create
TriggerEvent( this, "constructor" )
end on

on n_cst_numerical.destroy
TriggerEvent( this, "destructor" )
end on

