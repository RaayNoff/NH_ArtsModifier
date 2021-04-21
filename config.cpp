////////////////////////////////////////////////////////////////////
//DeRap: NH_ArtsModifier\config.bin
//Produced from mikero's Dos Tools Dll version 7.79
//https://mikero.bytex.digital/Downloads
//'now' is Wed Apr 21 13:43:32 2021 : 'file' last modified on Wed Apr 21 12:29:48 2021
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class NH_ArtsModifier
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Scripts","NH_Scripts","NH_Gear_Artefacts"};
	};
};
class CfgMods
{
	class NH_ArtsModifier
	{
		dir = "NH_ArtsModifier";
		name = "NH_ArtsModifier";
		credits = "";
		author = "RaayNoff";
		authorID = "0";
		version = "0.11";
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				vDCue = "";
				files[] = {"NH_ArtsModifier/scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class NH_art_Base;
	class NH_art_vivert: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_VIVERT;
	};
	class NH_art_soul: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_SOUL;
	};
	class NH_art_fireball: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_FIREBALL;
	};
	class NH_art_medusa: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_MEDUSA;
	};
	class NH_art_mincer_meat: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_MINCER_MEAT;
	};
	class NH_art_dummy_dummy: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_DUMMY_DUMMY;
	};
	class NH_art_dummy_battery: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_DUMMY_BATTERY;
	};
	class NH_art_eye: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_EYE;
	};
	class NH_art_fuzz_kolobok: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_FUZZ_KOLOBOK;
	};
	class NH_art_kristall: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_KRISTALL;
	};
	class NH_art_psi_field: NH_art_Base
	{
		ArtModifier = NHArtefactsModifiers.MDF_ART_PSI_FIELd;
	};
};
