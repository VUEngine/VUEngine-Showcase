/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © 3D meshes by Julian Leucht (JnL) <j.leucht@gmx.net>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <Ball.h>
#include <Mesh.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const PixelVector ProductionSiteMeshesSegments[][2]=
{
	// base
	{
		{0, 0, 0, 0}, 
		{-192, 0, 0, 0}
	},
	{
		{-192, 0, 0, 0}, 
		{-384, 0, 0, 0}
	},
	{
		{0, 0, 0, 0}, 
		{0, 0, 160, 0}
	},
	{
		{-384, 0, 0, 0}, 
		{-384, 0, 160, 0}
	},
	{
		{-384, 0, 160, 0}, 
		{0, 0, 160, 0}
	},

	{
		{0, -128, 0, 0}, 
		{-192, -128, 0, 0}
	},
	{
		{-192, -128, 0, 0}, 
		{-384, -128, 0, 0}
	},
	{
		{0, -128, 0, 0}, 
		{0, -128, 160, 0}
	},
	{
		{-384, -128, 0, 0}, 
		{-384, -128, 160, 0}
	},
	{
		{-384, -128, 160, 0}, 
		{0, -128, 160, 0}
	},

	{
		{0, 0, 0, 0}, 
		{0, -128, 0, 0}
	},
	{
		{0, 0, 160, 0}, 
		{0, -128, 160, 0}
	},
	{
		{-384, 0, 0, 0}, 
		{-384, -128, 0, 0}
	},
	{
		{-384, 0, 160, 0}, 
		{-384, -128, 160, 0}
	},

	// door
	{
		{-64, 0, 0, 0}, 
		{-64, -64, 0, 0}
	},
	{
		{-88, 0, 0, 0}, 
		{-88, -64, 0, 0}
	},
	{
		{-112, 0, 0, 0}, 
		{-112, -64, 0, 0}
	},
	{
		{-112, -64, 0, 0}, 
		{-64, -64, 0, 0}
	},

	// fußweg, 64 von Straße entfernt
	{
		{-64, 0, 0, 0}, 
		{-64, 0, -64, 0}
	},
	{
		{-112, 0, 0, 0}, 
		{-112, 0, -64, 0}
	},

	// window right door, r=4
	{
		{-72, -48, 0, 0}, 
		{-72.14, -49.04, 0, 0}
	},	
	{
		{-72.14, -49.04, 0, 0}, 
		{-72.54, -50, 0, 0}
	},
	{
		{-72.54, -50, 0, 0}, 
		{-73.17, -50.83, 0, 0}
	},
	{
		{-73.17, -50.83, 0, 0}, 
		{-74, -51.46, 0, 0}
	},
	{
		{-74, -51.46, 0, 0}, 
		{-74.96, -51.86, 0, 0}
	},
	{
		{-74.96, -51.86, 0, 0}, 
		{-76, -52, 0, 0}
	},

	{
		{-80, -48, 0, 0}, 
		{-79.86, -49.04, 0, 0}
	},	
	{
		{-79.86, -49.04, 0, 0}, 
		{-79.46, -50, 0, 0}
	},
	{
		{-79.46, -50, 0, 0}, 
		{-78.83, -50.83, 0, 0}
	},
	{
		{-78.83, -50.83, 0, 0}, 
		{-78, -51.46, 0, 0}
	},
	{
		{-78, -51.46, 0, 0}, 
		{-77.04, -51.86, 0, 0}
	},
	{
		{-77.04, -51.86, 0, 0}, 
		{-76, -52, 0, 0}
	},

	{
		{-72, -48, 0, 0}, 
		{-72.14, -46.96, 0, 0}
	},	
	{
		{-72.14, -46.96, 0, 0}, 
		{-72.54, -46, 0, 0}
	},
	{
		{-72.54, -46, 0, 0}, 
		{-73.17, -45.17, 0, 0}
	},
	{
		{-73.17, -45.17, 0, 0}, 
		{-74, -44.54, 0, 0}
	},
	{
		{-74, -44.54, 0, 0}, 
		{-74.96, -44.14, 0, 0}
	},
	{
		{-74.96, -44.14, 0, 0}, 
		{-76, -44, 0, 0}
	},

	{
		{-80, -48, 0, 0}, 
		{-79.86, -46.96, 0, 0}
	},	
	{
		{-79.86, -46.96, 0, 0}, 
		{-79.46, -46, 0, 0}
	},
	{
		{-79.46, -46, 0, 0}, 
		{-78.83, -45.17, 0, 0}
	},
	{
		{-78.83, -45.17, 0, 0}, 
		{-78, -44.54, 0, 0}
	},
	{
		{-78, -44.54, 0, 0}, 
		{-77.04, -44.14, 0, 0}
	},
	{
		{-77.04, -44.14, 0, 0}, 
		{-76, -44, 0, 0}
	},

	// window left door
	{
		{-96, -48, 0, 0}, 
		{-96.14, -49.04, 0, 0}
	},	
	{
		{-96.14, -49.04, 0, 0}, 
		{-96.54, -50, 0, 0}
	},
	{
		{-96.54, -50, 0, 0}, 
		{-97.17, -50.83, 0, 0}
	},
	{
		{-97.17, -50.83, 0, 0}, 
		{-98, -51.46, 0, 0}
	},
	{
		{-98, -51.46, 0, 0}, 
		{-98.96, -51.86, 0, 0}
	},
	{
		{-98.96, -51.86, 0, 0}, 
		{-100, -52, 0, 0}
	},

	{
		{-104, -48, 0, 0}, 
		{-103.86, -49.04, 0, 0}
	},	
	{
		{-103.86, -49.04, 0, 0}, 
		{-103.46, -50, 0, 0}
	},
	{
		{-103.46, -50, 0, 0}, 
		{-102.83, -50.83, 0, 0}
	},
	{
		{-102.83, -50.83, 0, 0}, 
		{-102, -51.46, 0, 0}
	},
	{
		{-102, -51.46, 0, 0}, 
		{-101.04, -51.86, 0, 0}
	},
	{
		{-101.04, -51.86, 0, 0}, 
		{-100, -52, 0, 0}
	},

	{
		{-96, -48, 0, 0}, 
		{-96.14, -46.96, 0, 0}
	},	
	{
		{-96.14, -46.96, 0, 0}, 
		{-96.54, -46, 0, 0}
	},
	{
		{-96.54, -46, 0, 0}, 
		{-97.17, -45.17, 0, 0}
	},
	{
		{-97.17, -45.17, 0, 0}, 
		{-98, -44.54, 0, 0}
	},
	{
		{-98, -44.54, 0, 0}, 
		{-98.96, -44.14, 0, 0}
	},
	{
		{-98.96, -44.14, 0, 0}, 
		{-100, -44, 0, 0}
	},

	{
		{-104, -48, 0, 0}, 
		{-103.86, -46.96, 0, 0}
	},	
	{
		{-103.86, -46.96, 0, 0}, 
		{-103.46, -46, 0, 0}
	},
	{
		{-103.46, -46, 0, 0}, 
		{-102.83, -45.17, 0, 0}
	},
	{
		{-102.83, -45.17, 0, 0}, 
		{-102, -44.54, 0, 0}
	},
	{
		{-102, -44.54, 0, 0}, 
		{-101.04, -44.14, 0, 0}
	},
	{
		{-101.04, -44.14, 0, 0}, 
		{-100, -44, 0, 0}
	},

	// window
	{
		{-152, -56, 0, 0}, 
		{-152, -96, 0, 0}
	},
	{
		{-152, -56, 0, 0}, 
		{-352, -56, 0, 0}
	},
	{
		{-352, -56, 0, 0}, 
		{-352, -96, 0, 0}
	},
	{
		{-152, -96, 0, 0}, 
		{-352, -96, 0, 0}
	},
	{
		{-312, -56, 0, 0}, 
		{-312, -96, 0, 0}
	},
	{
		{-272, -56, 0, 0}, 
		{-272, -96, 0, 0}
	},
	{
		{-232, -56, 0, 0}, 
		{-232, -96, 0, 0}
	},
	{
		{-192, -56, 0, 0}, 
		{-192, -96, 0, 0}
	},

	// Schräges Dach
	{
		{-332, -128, 16, 0}, 
		{-156, -128, 16, 0}
	},
	{
		{-332, -128, 144, 0}, 
		{-156, -128, 144, 0}
	},
	{
		{-332, -128, 16, 0}, 
		{-332, -192, 16, 0}
	},
	{
		{-332, -128, 16, 0}, 
		{-332, -128, 144, 0}
	},
	{
		{-332, -128, 144, 0}, 
		{-332, -192, 144, 0}
	},
	{
		{-332, -192, 16, 0}, 
		{-332, -192, 144, 0}
	},
	{
		{-332, -192, 144, 0}, 
		{-288, -128, 144, 0}
	},
	{
		{-332, -192, 16, 0}, 
		{-288, -128, 16, 0}
	},

	{
		{-288, -128, 16, 0}, 
		{-288, -176, 16, 0}
	},
	{
		{-288, -128, 144, 0}, 
		{-288, -176, 144, 0}
	},
	{
		{-288, -176, 144, 0}, 
		{-244, -128, 144, 0}
	},
	{
		{-288, -176, 16, 0}, 
		{-244, -128, 16, 0}
	},
	{
		{-288, -176, 16, 0}, 
		{-288, -176, 144, 0}
	},

	{
		{-244, -128, 144, 0}, 
		{-244, -160, 144, 0}
	},
	{
		{-244, -128, 16, 0}, 
		{-244, -160, 16, 0}
	},
	{
		{-244, -160, 144, 0}, 
		{-244, -160, 16, 0}
	},
	{
		{-244, -160, 144, 0}, 
		{-200, -128, 144, 0}
	},
	{
		{-244, -160, 16, 0}, 
		{-200, -128, 16, 0}
	},

	{
		{-200, -144, 16, 0}, 
		{-200, -128, 16, 0}
	},
	{
		{-200, -144, 144, 0}, 
		{-200, -128, 144, 0}
	},
	{
		{-200, -144, 144, 0}, 
		{-200, -144, 16, 0}
	},
	{
		{-200, -144, 144, 0}, 
		{-156, -128, 144, 0}
	},
	{
		{-200, -144, 16, 0}, 
		{-156, -128, 16, 0}
	},
	{
		{-156, -128, 144, 0}, 
		{-156, -128, 16, 0}
	},

	// Schlot 1 Exit
	{
		{16-72, 0-224, 0+64, 0}, 
		{15.54-72, 0-224, 4.14+64, 0}
	},
	{
		{15.54-72, 0-224, 4.14+64, 0}, 
		{13.86-72, 0-224, 8+64, 0}
	},
	{
		{13.86-72, 0-224, 8+64, 0}, 
		{11.31-72, 0-224, 11.31+64, 0}
	},
	{
		{11.31-72, 0-224, 11+64, 0}, 
		{8-72, 0-224, 13.86+64, 0}
	},
	{
		{8-72, 0-224, 13.86+64, 0}, 
		{4.14-72, 0-224, 15.45+64, 0}
	},
	{
		{4.14-72, 0-224, 15.45+64, 0}, 
		{0-72, 0-224, 16+64, 0}
	},

	{
		{-16-72, 0-224, 0+64, 0}, 
		{-15.54-72, 0-224, 4.14+64, 0}
	},
	{
		{-15.54-72, 0-224, 4.14+64, 0}, 
		{-13.86-72, 0-224, 8+64, 0}
	},
	{
		{-13.86-72, 0-224, 8+64, 0}, 
		{-11.31-72, 0-224, 11.31+64, 0}
	},
	{
		{-11.31-72, 0-224, 11+64, 0}, 
		{-8-72, 0-224, 13.86+64, 0}
	},
	{
		{-8-72, 0-224, 13.86+64, 0}, 
		{-4.14-72, 0-224, 15.45+64, 0}
	},
	{
		{-4.14-72, 0-224, 15.45+64, 0}, 
		{0-72, 0-224, 16+64, 0}
	},

	{
		{-16-72, 0-224, 0+64, 0}, 
		{-15.54-72, 0-224, -4.14+64, 0}
	},
	{
		{-15.54-72, 0-224, -4.14+64, 0}, 
		{-13.86-72, 0-224, -8+64, 0}
	},
	{
		{-13.86-72, 0-224, -8+64, 0}, 
		{-11.31-72, 0-224, -11.31+64, 0}
	},
	{
		{-11.31-72, 0-224, -11+64, 0}, 
		{-8-72, 0-224, -13.86+64, 0}
	},
	{
		{-8-72, 0-224, -13.86+64, 0}, 
		{-4.14-72, 0-224, -15.45+64, 0}
	},
	{
		{-4.14-72, 0-224, -15.45+64, 0}, 
		{0-72, 0-224, -16+64, 0}
	},

	{
		{16-72, 0-224, 0+64, 0}, 
		{15.54-72, 0-224, -4.14+64, 0}
	},
	{
		{15.54-72, 0-224, -4.14+64, 0}, 
		{13.86-72, 0-224, -8+64, 0}
	},
	{
		{13.86-72, 0-224, -8+64, 0}, 
		{11.31-72, 0-224, -11.31+64, 0}
	},
	{
		{11.31-72, 0-224, -11+64, 0}, 
		{8-72, 0-224, -13.86+64, 0}
	},
	{
		{8-72, 0-224, -13.86+64, 0}, 
		{4.14-72, 0-224, -15.45+64, 0}
	},
	{
		{4.14-72, 0-224, -15.45+64, 0}, 
		{0-72, 0-224, -16+64, 0}
	},

	// Schlot 1
	{
		{16-72, 0-224, 0+64, 0}, 
		{16-72, 0-224+96, 0+64, 0}
	},
	/*{
		{15.54-72, 0-224, 4.14+64, 0}, 
		{15.54-72, 0-224+96, 4.14+64, 0}
	},*/
	{
		{13.86-72, 0-224, 8+64, 0}, 
		{13.86-72, 0-224+96, 8+64, 0}
	},
	/*{
		{11.31-72, 0-224, 11.31+64, 0}, 
		{11.31-72, 0-224+96, 11.31+64, 0}
	},*/
	{
		{8-72, 0-224, 13.86+64, 0}, 
		{8-72, 0-224+96, 13.86+64, 0}
	},
	/*{
		{4.14-72, 0-224, 15.45+64, 0}, 
		{4.14-72, 0-224+96, 15.45+64, 0}
	},*/
	{
		{0-72, 0-224, 16+64, 0}, 
		{0-72, 0-224+96, 16+64, 0}
	},

	{
		{-16-72, 0-224, 0+64, 0}, 
		{-16-72, 0-224+96, 0+64, 0}
	},
	/*{
		{-15.54-72, 0-224, 4.14+64, 0}, 
		{-15.54-72, 0-224+96, 4.14+64, 0}
	},*/
	{
		{-13.86-72, 0-224, 8+64, 0}, 
		{-13.86-72, 0-224+96, 8+64, 0}
	},
	/*{
		{-11.31-72, 0-224, 11.31+64, 0}, 
		{-11.31-72, 0-224+96, 11.31+64, 0}
	},*/
	{
		{-8-72, 0-224, 13.86+64, 0}, 
		{-8-72, 0-224+96, 13.86+64, 0}
	},
	/*{
		{-4.14-72, 0-224, 15.45+64, 0}, 
		{-4.14-72, 0-224+96, 15.45+64, 0}
	},*/

	/*{
		{-15.54-72, 0-224, -4.14+64, 0}, 
		{-15.54-72, 0-224+96, -4.14+64, 0}
	},*/
	{
		{-13.86-72, 0-224, -8+64, 0}, 
		{-13.86-72, 0-224+96, -8+64, 0}
	},
	/*{
		{-11.31-72, 0-224, -11+64, 0}, 
		{-11.31-72, 0-224+96, -11+64, 0}
	},*/
	{
		{-8-72, 0-224, -13.86+64, 0}, 
		{-8-72, 0-224+96, -13.86+64, 0}
	},
	/*{
		{-4.14-72, 0-224, -15.45+64, 0}, 
		{-4.14-72, 0-224+96, -15.45+64, 0}
	},*/

	/*{
		{15.54-72, 0-224, -4.14+64, 0}, 
		{15.54-72, 0-224+96, -4.14+64, 0}
	},*/
	{
		{13.86-72, 0-224, -8+64, 0}, 
		{13.86-72, 0-224+96, -8+64, 0}
	},
	/*{
		{11.31-72, 0-224, -11+64, 0}, 
		{11.31-72, 0-224+96, -11+64, 0}
	},*/
	{
		{8-72, 0-224, -13.86+64, 0}, 
		{8-72, 0-224+96, -13.86+64, 0}
	},
	/*{
		{4.14-72, 0-224, -15.45+64, 0}, 
		{4.14-72, 0-224+96, -15.45+64, 0}
	},*/
	{
		{0-72, 0-224, -16+64, 0}, 
		{0-72, 0-224+96, -16+64, 0}
	},

		// Schlot 1 Eingang
	{
		{16-72, 0-224+96, 0+64, 0}, 
		{15.54-72, 0-224+96, 4.14+64, 0}
	},
	{
		{15.54-72, 0-224+96, 4.14+64, 0}, 
		{13.86-72, 0-224+96, 8+64, 0}
	},
	{
		{13.86-72, 0-224+96, 8+64, 0}, 
		{11.31-72, 0-224+96, 11.31+64, 0}
	},
	{
		{11.31-72, 0-224+96, 11+64, 0}, 
		{8-72, 0-224+96, 13.86+64, 0}
	},
	{
		{8-72, 0-224+96, 13.86+64, 0}, 
		{4.14-72, 0-224+96, 15.45+64, 0}
	},
	{
		{4.14-72, 0-224+96, 15.45+64, 0}, 
		{0-72, 0-224+96, 16+64, 0}
	},

	{
		{-16-72, 0-224+96, 0+64, 0}, 
		{-15.54-72, 0-224+96, 4.14+64, 0}
	},
	{
		{-15.54-72, 0-224+96, 4.14+64, 0}, 
		{-13.86-72, 0-224+96, 8+64, 0}
	},
	{
		{-13.86-72, 0-224+96, 8+64, 0}, 
		{-11.31-72, 0-224+96, 11.31+64, 0}
	},
	{
		{-11.31-72, 0-224+96, 11+64, 0}, 
		{-8-72, 0-224+96, 13.86+64, 0}
	},
	{
		{-8-72, 0-224+96, 13.86+64, 0}, 
		{-4.14-72, 0-224+96, 15.45+64, 0}
	},
	{
		{-4.14-72, 0-224+96, 15.45+64, 0}, 
		{0-72, 0-224+96, 16+64, 0}
	},

	{
		{-16-72, 0-224+96, 0+64, 0}, 
		{-15.54-72, 0-224+96, -4.14+64, 0}
	},
	{
		{-15.54-72, 0-224+96, -4.14+64, 0}, 
		{-13.86-72, 0-224+96, -8+64, 0}
	},
	{
		{-13.86-72, 0-224+96, -8+64, 0}, 
		{-11.31-72, 0-224+96, -11.31+64, 0}
	},
	{
		{-11.31-72, 0-224+96, -11+64, 0}, 
		{-8-72, 0-224+96, -13.86+64, 0}
	},
	{
		{-8-72, 0-224+96, -13.86+64, 0}, 
		{-4.14-72, 0-224+96, -15.45+64, 0}
	},
	{
		{-4.14-72, 0-224+96, -15.45+64, 0}, 
		{0-72, 0-224+96, -16+64, 0}
	},

	{
		{16-72, 0-224+96, 0+64, 0}, 
		{15.54-72, 0-224+96, -4.14+64, 0}
	},
	{
		{15.54-72, 0-224+96, -4.14+64, 0}, 
		{13.86-72, 0-224+96, -8+64, 0}
	},
	{
		{13.86-72, 0-224+96, -8+64, 0}, 
		{11.31-72, 0-224+96, -11.31+64, 0}
	},
	{
		{11.31-72, 0-224+96, -11+64, 0}, 
		{8-72, 0-224+96, -13.86+64, 0}
	},
	{
		{8-72, 0-224+96, -13.86+64, 0}, 
		{4.14-72, 0-224+96, -15.45+64, 0}
	},
	{
		{4.14-72, 0-224+96, -15.45+64, 0}, 
		{0-72, 0-224+96, -16+64, 0}
	},

	// Tür Seite mit Rampe
	{
		{0, -32, 48, 0}, 
		{0, -104, 48, 0}
	},
	{
		{0, -32, 112, 0}, 
		{0, -104, 112, 0}
	},
	{
		{0, -104, 48, 0}, 
		{0, -104, 112, 0}
	},
	{
		{0, -32, 112, 0}, 
		{64, 0, 112, 0}
	},
	{
		{0, -32, 48, 0}, 
		{64, 0, 48, 0}
	},
	{
		{64, 0, 48, 0}, 
		{64, 0, 112, 0}
	},
	{
		{0, -32, 48, 0}, 
		{0, -32, 112, 0}
	},
	{
		{0, -44, 48, 0}, 
		{0, -44, 112, 0}
	},
	{
		{0, -56, 48, 0}, 
		{0, -56, 112, 0}
	},
	{
		{0, -68, 48, 0}, 
		{0, -68, 112, 0}
	},
	{
		{0, -80, 48, 0}, 
		{0, -80, 112, 0}
	},
		{
		{0, -92, 48, 0}, 
		{0, -92, 112, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const ProductionSiteWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec ProductionSiteWireframeSpec =
{
	{
		{
			// Component
			{
				// Allocator
				__TYPE(Mesh),

				// Component type
				kWireframeComponent
			},

			// Array of function animations
			(const AnimationFunction**)NULL
		},

		// Displacement relative to the owner's spatial position
		{0, 0, 0},
		
		// Wireframe's lines' color
		__COLOR_BLACK,

		// Transparent
		__TRANSPARENCY_NONE,

		// Flag to render the wireframe in interlaced mode
		false
	},

	// Segments that compose the mesh
	(PixelVector(*)[2])ProductionSiteMeshesSegments
};

ComponentSpec* const ProductionSiteActorComponentSpecs[] = 
{
	(ComponentSpec*)&ProductionSiteWireframeSpec,
	NULL
};

ActorROMSpec ProductionSiteActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)ProductionSiteActorComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Animation to play automatically
	NULL
};
