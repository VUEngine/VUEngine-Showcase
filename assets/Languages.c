///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <I18n.h>
#include <Languages.h>


//---------------------------------------------------------------------------------------------------------
//                                              DECLARATIONS                                               
//---------------------------------------------------------------------------------------------------------

extern LangROMSpec EnglishLanguageSpec;
extern EntitySpec FlagUnitedKingdomEntity;
extern LangROMSpec GermanLanguageSpec;
extern EntitySpec FlagGermanyEntity;
extern LangROMSpec SpanishLanguageSpec;
extern EntitySpec FlagSpainEntity;


//---------------------------------------------------------------------------------------------------------
//                                               DEFINITIONS                                               
//---------------------------------------------------------------------------------------------------------

LangROMSpec* const _languages[] =
{
	&EnglishLanguageSpec,
	&GermanLanguageSpec,
	&SpanishLanguageSpec,
	
	NULL
};

const char* const EnglishLanguageStrings[] =
{
    /* kStringAutomaticPauseBody: */
    "Please take a rest!",
    /* kStringAutomaticPauseSelectionBody: */
    "The Automatic Pause feature will\nremind you to take a break from\nplaying approx. every 30 minutes",
    /* kStringAutomaticPauseSelectionOff: */
    "Off",
    /* kStringAutomaticPauseSelectionOn: */
    "On",
    /* kStringAutomaticPauseSelectionTitle: */
    "AUTOMATIC PAUSE",
    /* kStringAutomaticPauseTitle: */
    "AUTOMATIC PAUSE",
    /* kStringLanguageSelectTitle: */
    "LANGUAGE SELECT",
    /* kStringPostProcessingEffects: */
    "Hello, World!",
    /* kStringPrecautionScreenBody: */
    "     IMPORTANT\nREAD INSTRUCTION AND\nPRECAUTION BOOKLETS\n  BEFORE OPERATING",
};

const LangROMSpec EnglishLanguageSpec =
{
	// language name
	"English",

	// flag entity
	&FlagUnitedKingdomEntity,
	
	// strings
	(const char**)EnglishLanguageStrings
};

const char* const GermanLanguageStrings[] =
{
    /* kStringAutomaticPauseBody: */
    "Bitte mache eine Pause!",
    /* kStringAutomaticPauseSelectionBody: */
    " Die Automatische Pause Funktion\nerinnert dich daran, das Spiel ca.\n  alle 30 Minuten zu pausieren",
    /* kStringAutomaticPauseSelectionOff: */
    "Aus",
    /* kStringAutomaticPauseSelectionOn: */
    "An",
    /* kStringAutomaticPauseSelectionTitle: */
    "AUTOMATISCHE PAUSE",
    /* kStringAutomaticPauseTitle: */
    "AUTOMATISCHE PAUSE",
    /* kStringLanguageSelectTitle: */
    "SPRACHAUSWAHL",
    /* kStringPostProcessingEffects: */
    "Hallo, Welt!",
    /* kStringPrecautionScreenBody: */
    "        WICHTIG\nBITTE LESEN SIE VOR DEM\n SPIELEN DIE ANLEITUNG\nUND SICHERHEITSHINWEISE",
};

const LangROMSpec GermanLanguageSpec =
{
	// language name
	"Deutsch",

	// flag entity
	&FlagGermanyEntity,
	
	// strings
	(const char**)GermanLanguageStrings
};

const char* const SpanishLanguageStrings[] =
{
    /* kStringAutomaticPauseBody: */
    "¡Por favor, tómese un descanso!",
    /* kStringAutomaticPauseSelectionBody: */
    " La función automática de pausa te\nrecordará que debes tomar un descanso\n  approximadamente cada 30 minutos",
    /* kStringAutomaticPauseSelectionOff: */
    "Apagado",
    /* kStringAutomaticPauseSelectionOn: */
    "Encendido",
    /* kStringAutomaticPauseSelectionTitle: */
    "PAUSA AUTOMÁTICA",
    /* kStringAutomaticPauseTitle: */
    "PAUSA AUTOMÁTICA",
    /* kStringLanguageSelectTitle: */
    "SELECCIONAR IDIOMA",
    /* kStringPostProcessingEffects: */
    "Hola Mundo!",
    /* kStringPrecautionScreenBody: */
    "         IMPORTANTE\n     LEE LOS LIBROS DE\nINSTRUCCIONES Y PRECAUCIONES\n       ANTES DE JUGAR",
};

const LangROMSpec SpanishLanguageSpec =
{
	// language name
	"Español",

	// flag entity
	&FlagSpainEntity,
	
	// strings
	(const char**)SpanishLanguageStrings
};
