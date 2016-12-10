/****************************************************************************
 * Visual Boy Advance GX
 *
 * Tantric September 2008
 *
 * vbagx.h
 *
 * This file controls overall program flow. Most things start and end here!
 ***************************************************************************/
#ifndef _VBAGX_H_
#define _VBAGX_H_

#include <unistd.h>

#include "filelist.h"
#include "utils/FreeTypeGX.h"

#define APPNAME 		"Visual Boy Advance GX"
#define APPVERSION 		"2.3.5"
#define APPFOLDER 		"vbagx"
#define PREF_FILE_NAME 	"settings.xml"
#define PAL_FILE_NAME 	"palettes.xml"

#define NOTSILENT 0
#define SILENT 1

const char pathPrefix[9][8] =
{ "", "sd:/", "usb:/", "dvd:/", "smb:/", "carda:/", "cardb:/" };

enum 
{
	DEVICE_AUTO,
	DEVICE_SD,
	DEVICE_USB,
	DEVICE_DVD,
	DEVICE_SMB,
	DEVICE_SD_SLOTA,
	DEVICE_SD_SLOTB
};

enum 
{
	FILE_SRAM,
	FILE_SNAPSHOT,
	FILE_ROM,
	FILE_BORDER_PNG
};

enum 
{
	LANG_JAPANESE = 0,
	LANG_ENGLISH,
	LANG_GERMAN,
	LANG_FRENCH,
	LANG_SPANISH,
	LANG_ITALIAN,
	LANG_DUTCH,
	LANG_SIMP_CHINESE,
	LANG_TRAD_CHINESE,
	LANG_KOREAN,
	LANG_PORTUGUESE,
	LANG_BRAZILIAN_PORTUGUESE,
	LANG_CATALAN,
	LANG_TURKISH,
	LANG_LENGTH
};

struct SGCSettings
{
	float	gbaZoomHor;    // GBA horizontal zoom amount
    float	gbaZoomVert;   // GBA vertical zoom amount
    float	gbZoomHor;     // GB horizontal zoom amount
    float	gbZoomVert;    // GB vertical zoom amount
	int     gbFixed;
	int     gbaFixed;
	int		AutoLoad;
    int		AutoSave;
    int		LoadMethod;    // For ROMS: Auto, SD, DVD, USB, Network (SMB)
	int		SaveMethod;    // For SRAM, Freeze, Prefs: Auto, SD, USB, SMB
    int		AppendAuto;    // 0 - no, 1 - yes
    int		videomode;     // 0 - automatic, 1 - NTSC (480i), 2 - Progressive (480p), 3 - PAL (50Hz), 4 - PAL (60Hz)
    int		scaling;       // 0 - default, 1 - partial stretch, 2 - stretch to fit, 3 - widescreen correction
	int		render;		   // 0 - original, 1 - filtered, 2 - unfiltered
	int		xshift;		   // video output shift
	int		yshift;
	int     colorize;      // colorize Mono Gameboy games
	int     gbaFrameskip;  // turn on auto-frameskip for GBA games
	int		WiiControls;   // Match Wii Game
	int		WiimoteOrientation;
	int		ExitAction;
	int		MusicVolume;
	int		SFXVolume;
	int		Rumble;
	int 	language;
	int		PreviewImage;
	
	int		OffsetMinutesUTC; // Used for clock on MBC3 and TAMA5
	int 	GBHardware;    // Mapped to gbEmulatorType in VBA
	int 	SGBBorder;
	int		BasicPalette;	// 0 - Green   1 - Monochrome
	
	char	LoadFolder[MAXPATHLEN];  // Path to game files
	char	LastFileLoaded[MAXPATHLEN]; //Last file loaded filename
	char	SaveFolder[MAXPATHLEN];  // Path to save files
	char	ScreenshotsFolder[MAXPATHLEN]; //Path to screenshots files
	char	CoverFolder[MAXPATHLEN]; 	//Path to cover files
	char	ArtworkFolder[MAXPATHLEN]; 	//Path to artwork files
	char 	ImageFolder[MAXPATHLEN]; 	//Saved image folder path 
	char	BorderFolder[MAXPATHLEN];  // Path to Super Game Boy border files

	char	smbip[80];
	char	smbuser[20];
	char	smbpwd[20];
	char	smbshare[20];
};
void ExitApp();
void ShutdownWii();
bool SupportedIOS(u32 ios);
bool SaneIOS(u32 ios);
extern struct SGCSettings GCSettings;
extern int ScreenshotRequested;
extern int ConfigRequested;
extern int ShutdownRequested;
extern int ExitRequested;
extern char appPath[];

extern FreeTypeGX *fontSystem[];

#endif
