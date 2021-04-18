modded class NH_art_Base extends ItemBase
{
	protected Particle 		m_ParticleEfx;
	protected EffectSound 	m_EngineLoop;
	protected bool 			m_PhysicsFired;
	int						m_ModifierID = NHModifiers1.MDF_ART_Modifier;
	protected PlayerBase	m_ModifiedPlayer;

	void NH_art_Base()
	{
		NHDebugPrint("NH_art_Base::NH_art_Base");
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnParticle, 100, false);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CreateLight, 100, false);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(IdleSound, 100, false);
		}
	}

	void ~NH_art_Base()
	{
		NHDebugPrint("NH_art_Base::~NH_art_Base");
		if(m_EngineLoop) m_EngineLoop.SoundStop();
	}
	
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		PlayerBase	old_player;
		PlayerBase	new_player;
		
		new_player = PlayerBase.Cast(newLoc.GetParent().GetHierarchyRootPlayer());
		old_player = PlayerBase.Cast(oldLoc.GetParent().GetHierarchyRootPlayer());
			
		if(new_player)
		{
			EntityAI parent = newLoc.GetParent();
			
			if(!parent.IsInherited(NH_ArtContainerBase))
			{
				if(!m_ModifiedPlayer)
				{
					new_player.GetModifiersManager().ActivateModifier(m_ModifierID);
					m_ModifiedPlayer = new_player;
					Print("Modifier has been added");
				}
				else
				{
					Print("Player has attached art in different slot");
				}
				return;
			}
			else if(parent.IsInherited(NH_ArtContainerBase))
			{
				if(m_ModifiedPlayer)
				{
					m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID);
					m_ModifiedPlayer = null;
					Print("Modifier was deleted");
				}
				return;
			}
			
		}
		
		if(old_player && (old_player != new_player))
		{
			m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID);
			Print("Player dropped an art " + m_ModifiedPlayer.ToString());
			m_ModifiedPlayer = null;
		}		
	}
	
	void SendModifier(PlayerBase player, bool condition)
	{
		if(condition)
		{
			player.GetModifiersManager().ActivateModifier(m_ModifierID);
			return;
		}
		
		player.GetModifiersManager().DeactivateModifier(m_ModifierID);
	}

	void CreateLight()
	{
		NHDebugPrint("NH_art_Base::CreateLight");
		if(MemoryPointExists("light"))
		{
			NHPointLight light = NHPointLight.Cast( ScriptedLightBase.CreateLight( NHPointLight, "0 0 0") );
			light.SetBrightnessTo(0.3);
			light.AttachOnMemoryPoint(this, "light");
			light.SetOrientation("0 0 0");
			light.SetColorToWhite();
		}
	}

	void IdleSound()
	{
		NHDebugPrint("NH_art_Base::IdleSound");
		if(GetIdleSoundSet() != string.Empty)
		{
			vector pos = GetPosition();
			if (!m_EngineLoop)
			{
				m_EngineLoop = SEffectManager.CreateSound(GetIdleSoundSet(), pos);
				m_EngineLoop.SetParent(this);
				m_EngineLoop.SetSoundWaveKind(WaveKind.WAVEEFFECTEX);
				m_EngineLoop.SetSoundFadeIn(1);
				m_EngineLoop.SetSoundFadeOut(1);
				m_EngineLoop.SetSoundLoop(true);
				m_EngineLoop.SetSoundVolume(GetIdleSoundVolume());
				m_EngineLoop.SoundPlay();
			}
		}
	}

	void SpawnParticle()
	{
		NHDebugPrint("NH_art_Base::SpawnParticle");
		if(GetParticleId() != -1)  m_ParticleEfx = Particle.PlayOnObject(GetParticleId(), this);
	}

	override void EEDelete(EntityAI parent)
	{
		NHDebugPrint("NH_art_Base::EEDelete");
		super.EEDelete(parent);
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( m_ParticleEfx )
				m_ParticleEfx.Stop();
		}
	}

	float GetIdleSoundVolume()
	{
		return 1;
	}

	string GetIdleSoundSet()
	{
		return string.Empty;
	}

	int GetParticleId()
	{
		return -1;
	}
}