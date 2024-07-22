/*/////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
/////////////////////////////////////////////////////////////////////////////////////////////////////////*/

OUTPUT_FORMAT("elf32-v810", "elf32-v810", "elf32-v810")
OUTPUT("a.elf") /* force elf format output */
OUTPUT_ARCH(v810)
TARGET(elf32-v810)
ENTRY(start)
SEARCH_DIR(.);

MEMORY
{
	dram (!r) : ORIGIN = 0x00035800, LENGTH = 32k
	wram (!r) : ORIGIN = 0x05000000, LENGTH = 64k
	exp  (r)  : ORIGIN = 0x04000000, LENGTH = 16M
	sram (!r) : ORIGIN = 0x06000000, LENGTH = 16M
	rom  (rx) : ORIGIN = 0x07000000, LENGTH = 16M
}

/*
If not defined, define interrupt
Handlers as system reset
*/

_dramVma = ORIGIN(dram);
_dataVma = ORIGIN(wram);
_expVma = ORIGIN(exp);
_sramVma = ORIGIN(sram);
_textVma = ORIGIN(rom);
_stack = ORIGIN(wram) + LENGTH(wram) - 64;

SECTIONS
{
	/* Read-only sections, merged into text segment: */
	.expdata _expVma (NOLOAD):
	{
		PROVIDE (_expDataStart = .);
		*(.expdata*)
		PROVIDE (_expDataEnd = .);
	} >exp = 0xFF

	.text _textVma :
	{
		PROVIDE (_textStart = .);
		*(.text*)
		PROVIDE (_textEnd = .);
	} >rom = 0xFF

	.rodata :
	{
		PROVIDE (_stringsStart = .);
		*(.strings*)
		PROVIDE (_stringsEnd = .);
		*(.rodata*)
	} >rom = 0xFF

	v = . + 0x20;

	/* Ram memory */
	_dataLma = .;
	.sdata _dataVma : AT(_dataLma)
	{
		PROVIDE (_dataStart = .);
		PROVIDE (_gp = . + 0x8000);
		*(.sdata*)
	} >wram = 0xFF

	.data ALIGN(2):
	{
		*(.data*)
		PROVIDE (_dataEnd = .);
	} >wram = 0xFF

	.dramdata _dramVma : AT(v + SIZEOF(.data) + SIZEOF(.sdata))
	{
		PROVIDE (_dramDirtyStart = .);
		*(.dramdirty*)
		PROVIDE (_dramDataStart = .);
		*(.dramdata*)
		PROVIDE (_dramDataEnd = .);
	} >dram = 0xFF

	.sramdata _sramVma : AT(v + SIZEOF(.data) + SIZEOF(.sdata) + SIZEOF(.dramdata)) SUBALIGN(2)
	{
		PROVIDE (_sramDataStart = .);
		*(.sramdata*)
		PROVIDE (_sramDataEnd = .);
	} >sram = 0xFF

	.sbss (NOLOAD):
	{
		PROVIDE (_bssStart = .);
		*(.sbss*)
		*(.scommon*)
	} >wram = 0xFF

	.bss (NOLOAD):
	{
		*(.bss*)
		*(COMMON)
		PROVIDE (_bssEnd = .);
	} >wram = 0xFF

	.drambss (NOLOAD): AT(_dramDataEnd)
	{
		PROVIDE(_dramBssStart = .);
		*(.drambss*)
		PROVIDE(_dramBssEnd = .);
	} >dram = 0xFF

	/* SRAM Work RAM */
	.srambss (NOLOAD): SUBALIGN(2)
	{
		PROVIDE(_sramBssStart = .);
		*(.srambss*)
		PROVIDE(_sramBssEnd = .);
	} >sram

	/* Prevent overlaps with vbvectors */
	/* The use of new variables is because GCC 4.7's linker doesn't override the v value */
	v1 = v + SIZEOF(.data) + SIZEOF(.sdata);

	/* Compute the vector address */
	/* This promotes . to a power of two */

	v2 = v1 + 0x1FF; 		/* add size of jump table */
	v3 = v2 & 0x00FFFFFF;
	v4 = v3 | (v3 >> 1);
	v5 = v4 | (v4 >> 2);
	v6 = v5 | (v5 >> 4);
	v7 = v6 | (v6 >> 8);
	v8 = v7 | (v7 >> 16);

	_vbvectorsvma = _textVma + v8 - 0x1FF;
	_rominfovma = _vbvectorsvma - 0x20;

	/* Place rom's info before the interrupt vectors */
	.rominfo _rominfovma :
	{
		KEEP (*(.rominfo))
	} >rom = 0xFF

	/* Place interrupt and reset vector at end of rom */
	.vbvectors _vbvectorsvma :
	{
		KEEP (*(.vbvectors))
	} >rom = 0xFF
}
