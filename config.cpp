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
	class NH_art_vivert;
	class NH_art_vivert1: NH_art_vivert
	{
		ArtModifier = 0;
	};
	class NH_art_soul;
	class NH_art_soul1: NH_art_soul
	{
		ArtModifier = 1;
	};
};
