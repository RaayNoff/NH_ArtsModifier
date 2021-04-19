enum NHArtefactsModifiers
{
	MDF_ART_VIVERT = 0,
};

modded class ModifiersManager
{
	override void Init()
	{
        NHDebugPrint("ModifiersManager::Init");
		super.Init();
		AddModifier(new NHArtModifierVivert);
	}
};