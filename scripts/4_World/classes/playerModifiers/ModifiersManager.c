enum NHModifiers1
{
  MDF_ART_Modifier
}

modded class ModifiersManager
{
	override void Init()
	{
        NHDebugPrint("ModifiersManager::Init");
		super.Init();
		AddModifier(new RadXMdfr);
		AddModifier(new ApplySplintMdfr);
		AddModifier(new NHRadiationSicknessMdfr);
		AddModifier(new NHArtModifier);
		//AddModifier(new MentalDisorderMdfr);
	}
}