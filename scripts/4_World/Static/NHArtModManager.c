ref NHArtModManager g_ArtModPM;
class NHArtModManager
{
	private static PlayerBase			m_Player;
	private static EntityAI				m_Art;
	private static bool					m_IsActivate;
	
	static void InitManager(PlayerBase player, ItemBase artefact, bool isActivate)
	{
		Print("NHArtModManager :: InitManager");
		m_Player				= player;
		m_Art					= artefact;
		m_IsActivate			= isActivate;
		PrintPrikols();
		SwitchNSetModifier(m_IsActivate);
	}
	
	static void PrintPrikols()
	{
		Print("NHArtModManager :: m_Player :: " + m_Player);
		Print("NHArtModManager :: m_Art :: " + m_Art);
		Print("NHArtModManager :: m_IsActivate :: " + m_IsActivate);
		Print("NHArtModManager :: ConfigGetInt :: " + m_Art.ConfigGetInt("ArtModifier"));
	}
	
	static void SwitchNSetModifier(bool isActivate = true)
	{
		Print("NHArtModManager :: SwitchNSetModifier");
		//gOvNo KoDe
		if(isActivate)
		{
			switch(m_Art.ConfigGetInt("ArtModifier"))
			{
				case 1:
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_VIVERT);
					break;
				case 2: 
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_SOUL);
					Print("Гондон должен активировать модификатор");
					break;
				case 3:
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_FIREBALL);
					break;
				case 4: 
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_MEDUSA);
					break;
				case 5:
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_MINCER_MEAT);
					break;
				case 6:
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_DUMMY_DUMMY);
					break;
				case 7:
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_DUMMY_BATTERY);
					break;
				case 8: 
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_EYE);
					break;
				case 9: 
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_FUZZ_KOLOBOK);
					break;
				case 10: 
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_KRISTALL);
					break;
				case 11:
					m_Player.GetModifiersManager().ActivateModifier(NHArtefactsModifiers.MDF_ART_PSI_FIELD);				
					break;
			}
		}
		else
		{
			switch(m_Art.ConfigGetInt("ArtModifier"))
			{
				case 1:
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_VIVERT);
					break;
				case 2: 
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_SOUL);
					break;
				case 3:
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_FIREBALL);
					break;
				case 4: 
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_MEDUSA);
					break;
				case 5:
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_MINCER_MEAT);
					break;
				case 6:
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_DUMMY_DUMMY);
					break;
				case 7:
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_DUMMY_BATTERY);
					break;
				case 8: 
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_EYE);
					break;
				case 9: 
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_FUZZ_KOLOBOK);
					break;
				case 10: 
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_KRISTALL);
					break;
				case 11:
					m_Player.GetModifiersManager().DeactivateModifier(NHArtefactsModifiers.MDF_ART_PSI_FIELD);				
					break;
			}
		}
	}
	
	static ref NHArtModManager GetArtModifierPluginManager()
	{
		return g_ArtModPM;
	}
}











