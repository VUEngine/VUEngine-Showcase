/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

OUTPUT_FORMAT("elf32-v810", "elf32-v810", "elf32-v810")
OUTPUT("a.elf") /* force elf format output */
OUTPUT_ARCH(v810)
TARGET(elf32-v810)
ENTRY(_start)
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

__dramVma = ORIGIN(dram);
__dataVma = ORIGIN(wram);
__expVma = ORIGIN(exp);
__sramVma = ORIGIN(sram);
__textVma = ORIGIN(rom);
__stack = ORIGIN(wram) + LENGTH(wram) - 64;

SECTIONS
{
	/* Read-only sections, merged into text segment: */
	.expdata __expVma (NOLOAD):
	{
		PROVIDE (__expDataStart = .);
		*(.expdata*)
		PROVIDE (__expDataEnd = .);
	} >exp = 0xFF

	.text __textVma : SUBALIGN(4)
	{
		PROVIDE (__textStart = .);
		*(.text*)
		PROVIDE (__textEnd = .);
	} >rom = 0xFF

	.rodata : SUBALIGN(4)
	{
		PROVIDE (__stringsStart = .);
		*(.strings*)
		PROVIDE (__stringsEnd = .);
		*(.rodata*)
	} >rom = 0xFF

	v = . + 0x20;

	/* Ram memory */
	__dataLma = .;
	.sdata __dataVma : AT(__dataLma) SUBALIGN(4)
	{
		PROVIDE (__dataStart = .);
		PROVIDE (__gp = . + 0x8000);
		*(.sdata*)
	} >wram = 0xFF

	.data ALIGN(2):
	{
		*(.data*)
		PROVIDE (__dataEnd = .);
	} >wram = 0xFF

	.dram_data __dramVma : AT(v + SIZEOF(.data) + SIZEOF(.sdata)) SUBALIGN(4)
	{
		PROVIDE (__dramDirtyStart = .);
		*(.dram_dirty*)
		PROVIDE (__dramDataStart = .);
		*(.dram_data*)
		PROVIDE (__dramDataEnd = .);
	} >dram = 0xFF

	.sram_data __sramVma : AT(v + SIZEOF(.data) + SIZEOF(.sdata) + SIZEOF(.dram_data)) SUBALIGN(2)
	{
		PROVIDE (__sramDataStart = .);
		*(.sram_data*)
		PROVIDE (__sramDataEnd = .);
	} >sram = 0xFF

	.sbss (NOLOAD): SUBALIGN(4)
	{
		PROVIDE (__bssStart = .);
		*(.sbss*)
		*(.scommon*)
	} >wram = 0xFF

	.bss (NOLOAD): SUBALIGN(4)
	{
		*(.bss*)
		*(COMMON)
		PROVIDE (__bssEnd = .);
	} >wram = 0xFF

	.dram_bss (NOLOAD): AT(__dramDataEnd) SUBALIGN(4)
	{
		PROVIDE(__dramBssStart = .);
		*(.dram_bss*)
		PROVIDE(__dramBssEnd = .);
	} >dram = 0xFF

	/* SRAM Work RAM */
	.sram_bss (NOLOAD): SUBALIGN(2)
	{
		PROVIDE(__sramBssStart = .);
		*(.sram_bss*)
		PROVIDE(__sramBssEnd = .);
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

	__vbvectors_vma = __textVma + v8 - 0x1FF;
	__rominfo_vma = __vbvectors_vma - 0x20;

	/* Place rom's info before the interrupt vectors */
	.rominfo __rominfo_vma :
	{
		KEEP (*(.rominfo))
	} >rom = 0xFF

	/* Place interrupt and reset vector at end of rom */
	.vbvectors __vbvectors_vma :
	{
		KEEP (*(.vbvectors))
	} >rom = 0xFF
}
