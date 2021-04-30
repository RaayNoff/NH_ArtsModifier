class NHArtefactsModifiers
{
	static int MDF_ART_VIVERT = 9193;
	static int MDF_ART_SOUL = 9485;
	static int MDF_ART_FIREBALL = 8585;
	static int MDF_ART_MEDUSA = 9274;
	static int MDF_ART_MINCER_MEAT = 7493;
	static int MDF_ART_DUMMY_DUMMY = 8698;
	static int MDF_ART_DUMMY_BATTERY = 9198;
	static int MDF_ART_EYE = 9878;
	static int MDF_ART_FUZZ_KOLOBOK = 8884;
	static int MDF_ART_KRISTALL = 48585;
	static int MDF_ART_PSI_FIELD = 8577;
};

modded class ModifiersManager
{
	override void Init()
	{
        NHDebugPrint("ModifiersManager::Init");
		super.Init();
		AddModifier(new NHArtModifierVivert);
		AddModifier(new NHArtModifierSoul);
		AddModifier(new NHArtModifierFireball);
	}
};