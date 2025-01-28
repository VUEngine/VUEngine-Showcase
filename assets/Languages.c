////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <I18n.h>
#include <Languages.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern LangROMSpec EnglishLanguageSpec;
extern ActorSpec FlagUnitedKingdomActorSpec;
extern LangROMSpec GermanLanguageSpec;
extern ActorSpec FlagGermanyActorSpec;
extern LangROMSpec SpanishLanguageSpec;
extern ActorSpec FlagSpainActorSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

LangROMSpec* const _languages[] =
{
	&EnglishLanguageSpec,
	&GermanLanguageSpec,
	&SpanishLanguageSpec,
	
	NULL
};

const char* const EnglishLanguageStrings[] =
{
    /* kStringActorCreationLabel: */
    "Actor creation",
    /* kStringActorDestructionLabel: */
    "Actor destruction",
    /* kStringActorsLabel: */
    "Actors",
    /* kStringAnimationsLabel: */
    "Animations",
    /* kStringAnimationSubtitle: */
    "ANIMATION",
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
    /* kStringBgmapMemoryLabel: */
    "BGMAP memory:",
    /* kStringCameraControlLabel: */
    "Camera control",
    /* kStringCharMemoryLabel: */
    "CHAR memory:",
    /* kStringClassesSubtitle: */
    "CLASSES",
    /* kStringClassExtensionLabel: */
    "Class extension",
    /* kStringClassMutationLabel: */
    "Class mutation",
    /* kStringCollisionsLabel: */
    "Collisions",
    /* kStringCommunicationsLabel: */
    "Communications",
    /* kStringConceptsSubtitle: */
    "CONCEPTS",
    /* kStringConnected: */
    "CONNECTED",
    /* kStringDwarfPlanetLabel: */
    "Dwarf Planet",
    /* kStringEffectSubtitle: */
    "EFFECT",
    /* kStringEventsLabel: */
    "Events",
    /* kStringFrameBuffersLabel: */
    "Frame buffers",
    /* kStringGameStatesLabel: */
    "Game states",
    /* kStringHiColorLabel: */
    "HiColor",
    /* kStringLanguageSelectTitle: */
    "LANGUAGE SELECT",
    /* kStringLinkedListsLabel: */
    "Linked lists",
    /* kStringMessagingLabel: */
    "Messaging",
    /* kStringMethodsSubtitle: */
    "METHODS",
    /* kStringModeLabel: */
    "Mode:",
    /* kStringMultiframeLabel: */
    "Multiframe",
    /* kStringMultiframeTextureLabel: */
    "The sprites share the\ngraphics but each can\nshow a different frame\nfrom the same texture",
    /* kStringNoLink: */
    "NO LINK",
    /* kStringNotSharedLabel: */
    "Not shared",
    /* kStringNotSharedTextureLabel: */
    "Each sprite has its\nown texture and its\nown set of tiles\n\nEach one has to be\nanimated individually",
    /* kStringOptimizedBgmapsLabel: */
    "Optimized BGMAPs",
    /* kStringOptimizedCharSetsLabel: */
    "Optimized CharSets",
    /* kStringOtherConceptsSubtitle: */
    "OTHER CONCEPTS",
    /* kStringParentingLabel: */
    "Parenting",
    /* kStringParticlesSubtitle: */
    "PARTICLES TYPE",
    /* kStringParticleSystemsLabel: */
    "Particle systems",
    /* kStringParticleTypesLabel: */
    "Particle types",
    /* kStringPauseTitle: */
    "PAUSE",
    /* kStringPhysicsLabel: */
    "Physics",
    /* kStringPostProcessingEffectsLabel: */
    "Post processing effects",
    /* kStringPrecautionScreenBody: */
    "     IMPORTANT\nREAD INSTRUCTION AND\nPRECAUTION BOOKLETS\n  BEFORE OPERATING",
    /* kStringRainLabel: */
    "Rain",
    /* kStringSharedLabel: */
    "Shared",
    /* kStringSharedTextureLabel: */
    "All sprites share\nthe same tiles set\nand the same texture\n\nOnly one of them\nneeds to be animated",
    /* kStringSoundPlaybackLabel: */
    "Sound playback",
    /* kStringSpecsLabel: */
    "Specs",
    /* kStringSpecsSubtitle: */
    "SPECS",
    /* kStringSpritesLabel: */
    "Sprites",
    /* kStringSpriteSubtitle: */
    "SPRITE",
    /* kStringStagesLabel: */
    "Stages",
    /* kStringStatefulActorsLabel: */
    "StatefulActors",
    /* kStringStateMachinesLabel: */
    "State machines",
    /* kStringStateTitle: */
    "STATE:",
    /* kStringTiltELabel: */
    "Tilt",
    /* kStringTimerSettingsLabel: */
    "Timer settings",
    /* kStringUserInputLabel: */
    "User input",
    /* kStringWireframesLabel: */
    "Wireframes",
    /* kStringWobbleLabel: */
    "Wobble",
    /* kStringYouDiedAgain: */
    "YOU DIED… AGAIN",
};

const LangROMSpec EnglishLanguageSpec =
{
	// language name
	"English",

	// flag actor
	&FlagUnitedKingdomActorSpec,
	
	// strings
	(const char**)EnglishLanguageStrings
};

const char* const GermanLanguageStrings[] =
{
    /* kStringActorCreationLabel: */
    "Actor-Konstruktoren",
    /* kStringActorDestructionLabel: */
    "Actor-Destruktoren",
    /* kStringActorsLabel: */
    "Actors",
    /* kStringAnimationsLabel: */
    "Animationen",
    /* kStringAnimationSubtitle: */
    "ANIMATION",
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
    /* kStringBgmapMemoryLabel: */
    "BGMAP-Speicher:",
    /* kStringCameraControlLabel: */
    "Kamerakontrolle",
    /* kStringCharMemoryLabel: */
    "CHAR-Speicher:",
    /* kStringClassesSubtitle: */
    "KLASSEN",
    /* kStringClassExtensionLabel: */
    "Klassenerweiterung",
    /* kStringClassMutationLabel: */
    "Klassenmutationen",
    /* kStringCollisionsLabel: */
    "Kollisionen",
    /* kStringCommunicationsLabel: */
    "Kommunikation",
    /* kStringConceptsSubtitle: */
    "KONZEPTE",
    /* kStringConnected: */
    "VERBUNDEN",
    /* kStringDwarfPlanetLabel: */
    "Zwergplanet",
    /* kStringEffectSubtitle: */
    "EFFECT",
    /* kStringEventsLabel: */
    "Ereignisse",
    /* kStringFrameBuffersLabel: */
    "Framebuffer",
    /* kStringGameStatesLabel: */
    "Spielzustände",
    /* kStringHiColorLabel: */
    "HiColor",
    /* kStringLanguageSelectTitle: */
    "SPRACHAUSWAHL",
    /* kStringLinkedListsLabel: */
    "Verkettete Listen",
    /* kStringMessagingLabel: */
    "Messaging",
    /* kStringMethodsSubtitle: */
    "METHODEN",
    /* kStringModeLabel: */
    "Modus:",
    /* kStringMultiframeLabel: */
    "Multiframe",
    /* kStringMultiframeTextureLabel: */
    "Sprites teilen sich die\nGrafiken, aber jedes kann\neinen anderen Frame\nderselben Textur zeigen",
    /* kStringNoLink: */
    "NICHT VERBUNDEN",
    /* kStringNotSharedLabel: */
    "Nicht geteilt",
    /* kStringNotSharedTextureLabel: */
    "Jedes Sprite hat seine\neigene Textur und einen\neigenen Kachelsatz\n\nJedes Sprite muss\neinzeln animiert werden",
    /* kStringOptimizedBgmapsLabel: */
    "Optimierte BGMAPs",
    /* kStringOptimizedCharSetsLabel: */
    "Optimierte CharSets",
    /* kStringOtherConceptsSubtitle: */
    "WEITERE KONZEPTE",
    /* kStringParentingLabel: */
    "Parenting",
    /* kStringParticlesSubtitle: */
    "PARTIKEL-TYP",
    /* kStringParticleSystemsLabel: */
    "Partikelsysteme",
    /* kStringParticleTypesLabel: */
    "Partikel-Typen",
    /* kStringPauseTitle: */
    "PAUSE",
    /* kStringPhysicsLabel: */
    "Physik",
    /* kStringPostProcessingEffectsLabel: */
    "Post-Processing Effekte",
    /* kStringPrecautionScreenBody: */
    "        WICHTIG\nBITTE LESEN SIE VOR DEM\n SPIELEN DIE ANLEITUNG\nUND SICHERHEITSHINWEISE",
    /* kStringRainLabel: */
    "Regen",
    /* kStringSharedLabel: */
    "Geteilt",
    /* kStringSharedTextureLabel: */
    "Alle Sprites teilen sich\ndenselben Kachelsatz\nund die selbe Textur\n\nNur ein Sprite\nmuss animiert werden",
    /* kStringSoundPlaybackLabel: */
    "Sound-Playback",
    /* kStringSpecsLabel: */
    "Specs",
    /* kStringSpecsSubtitle: */
    "SPECS",
    /* kStringSpritesLabel: */
    "Sprites",
    /* kStringSpriteSubtitle: */
    "SPRITE",
    /* kStringStagesLabel: */
    "Stages",
    /* kStringStatefulActorsLabel: */
    "Akteure",
    /* kStringStateMachinesLabel: */
    "Zustandsautomaten",
    /* kStringStateTitle: */
    "ZUSTAND:",
    /* kStringTiltELabel: */
    "Gekippt",
    /* kStringTimerSettingsLabel: */
    "Timer-Einstellungen",
    /* kStringUserInputLabel: */
    "Benutzereingaben",
    /* kStringWireframesLabel: */
    "Wireframes",
    /* kStringWobbleLabel: */
    "Taumeln",
    /* kStringYouDiedAgain: */
    "DU BIST TOT… ERNEUT",
};

const LangROMSpec GermanLanguageSpec =
{
	// language name
	"Deutsch",

	// flag actor
	&FlagGermanyActorSpec,
	
	// strings
	(const char**)GermanLanguageStrings
};

const char* const SpanishLanguageStrings[] =
{
    /* kStringActorCreationLabel: */
    "Actor: creación",
    /* kStringActorDestructionLabel: */
    "Actor: destrucción ",
    /* kStringActorsLabel: */
    "Actores",
    /* kStringAnimationsLabel: */
    "Animaciones",
    /* kStringAnimationSubtitle: */
    "ANIMACION",
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
    /* kStringBgmapMemoryLabel: */
    "Memoria BGMAP:",
    /* kStringCameraControlLabel: */
    "Control de cámara",
    /* kStringCharMemoryLabel: */
    "Memoria CHAR:",
    /* kStringClassesSubtitle: */
    "CLASES",
    /* kStringClassExtensionLabel: */
    "Extensiones de clase",
    /* kStringClassMutationLabel: */
    "Mutación de clases",
    /* kStringCollisionsLabel: */
    "Colisiones",
    /* kStringCommunicationsLabel: */
    "Comunicaciones",
    /* kStringConceptsSubtitle: */
    "CONCEPTOS",
    /* kStringConnected: */
    "CONECTADO",
    /* kStringDwarfPlanetLabel: */
    "Planeta Enano",
    /* kStringEffectSubtitle: */
    "EFECTO",
    /* kStringEventsLabel: */
    "Eventos",
    /* kStringFrameBuffersLabel: */
    "Búfer de video",
    /* kStringGameStatesLabel: */
    "Estados de juego",
    /* kStringHiColorLabel: */
    "HiColor",
    /* kStringLanguageSelectTitle: */
    "SELECCIONAR IDIOMA",
    /* kStringLinkedListsLabel: */
    "Listas enlazadas",
    /* kStringMessagingLabel: */
    "Mensajes",
    /* kStringMethodsSubtitle: */
    "METODOS",
    /* kStringModeLabel: */
    "Modo:",
    /* kStringMultiframeLabel: */
    "Multi fotograma",
    /* kStringMultiframeTextureLabel: */
    "Los sprites comparten\nlas mismas teselas\ny la misma textura\nSólo uno de ellos",
    /* kStringNoLink: */
    "NO CONECTADO",
    /* kStringNotSharedLabel: */
    "No compartida",
    /* kStringNotSharedTextureLabel: */
    "Cada sprite tiene su\npropia textura y \nconjunto de teselas\n\nCada una debe ser\nanimada individualmente",
    /* kStringOptimizedBgmapsLabel: */
    "BGMAPs optimizados",
    /* kStringOptimizedCharSetsLabel: */
    "CharSets optimizados",
    /* kStringOtherConceptsSubtitle: */
    "OTROS CONCEPTOS",
    /* kStringParentingLabel: */
    "Contenedores",
    /* kStringParticlesSubtitle: */
    "TIPO DE PARTICULAS",
    /* kStringParticleSystemsLabel: */
    "Sistemas de partículas",
    /* kStringParticleTypesLabel: */
    "Tipos de partículas",
    /* kStringPauseTitle: */
    "PAUSA",
    /* kStringPhysicsLabel: */
    "Física",
    /* kStringPostProcessingEffectsLabel: */
    "Efectos gráficos",
    /* kStringPrecautionScreenBody: */
    "         IMPORTANTE\n     LEE LOS LIBROS DE\nINSTRUCCIONES Y PRECAUCIONES\n       ANTES DE JUGAR",
    /* kStringRainLabel: */
    "Lluvia",
    /* kStringSharedLabel: */
    "Compartida",
    /* kStringSharedTextureLabel: */
    "Los sprites comparten\nlas mismas teselas\ny la misma textura\n\nSólo uno de ellos\nnecesita ser animado",
    /* kStringSoundPlaybackLabel: */
    "Reproducción de sonido",
    /* kStringSpecsLabel: */
    "Especificaciones",
    /* kStringSpecsSubtitle: */
    "ESPECIFICACIONES",
    /* kStringSpritesLabel: */
    "Sprites",
    /* kStringSpriteSubtitle: */
    "SPRITE",
    /* kStringStagesLabel: */
    "Escenas",
    /* kStringStatefulActorsLabel: */
    "StatefulActores",
    /* kStringStateMachinesLabel: */
    "Máquinas de estado",
    /* kStringStateTitle: */
    "ESTADO:",
    /* kStringTiltELabel: */
    "Inclinado",
    /* kStringTimerSettingsLabel: */
    "Configuración de reloj",
    /* kStringUserInputLabel: */
    "Entrada de usuario",
    /* kStringWireframesLabel: */
    "Wireframes",
    /* kStringWobbleLabel: */
    "Ondulado",
    /* kStringYouDiedAgain: */
    "MORISTE… OTRA VEZ",
};

const LangROMSpec SpanishLanguageSpec =
{
	// language name
	"Español",

	// flag actor
	&FlagSpainActorSpec,
	
	// strings
	(const char**)SpanishLanguageStrings
};
