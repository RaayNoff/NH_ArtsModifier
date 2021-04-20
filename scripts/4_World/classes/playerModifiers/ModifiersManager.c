enum NHArtefactsModifiers
{
	MDF_ART_VIVERT = 0,
	MDF_ART_SOUL = 1,
};

modded class ModifiersManager
{
	override void Init()
	{
        NHDebugPrint("ModifiersManager::Init");
		super.Init();
		AddModifier(new NHArtModifierVivert);
		AddModifier(new NHArtModifierSoul);
	}
};