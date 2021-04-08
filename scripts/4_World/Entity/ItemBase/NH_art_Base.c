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
		
		if(newLoc.GetParent())
		{
			new_player = PlayerBase.Cast(newLoc.GetParent().GetHierarchyRootPlayer());
		}
		
		if(oldLoc.GetParent())
		{
			Print("EEItemLocationChanged :: oldLoc.GetParent() :: " + oldLoc.GetParent())
			old_player = PlayerBase.Cast(oldLoc.GetParent().GetHierarchyRootPlayer());
			Print("EEItemLocationChanged :: old_player :: " + old_player);
		}
			
		if(new_player)
		{
			Print("EEItemLocationChanged :: if(new_player) :: " + new_player);
			EntityAI parent = newLoc.GetParent(); //Получаем родителя для нового расположения слота
			Print("EEItemLocationChanged :: EntityAI parent :: " + parent);
			if(!parent.IsInherited(NH_ArtContainerBase)) //Если родителем неявляется предмет, относящийся к NH_ArtContainerBase
			{
				Print("EEItemLocationChanged :: if(!parent.IsInherited(NH_ArtContainerBase))" + parent.IsInherited(NH_ArtContainerBase));
				m_ModifiedPlayer = new_player; //Запоминаем игрока
				Print("m_ModifiedPlayer :: " + m_ModifiedPlayer);
				Print("new_player :: " + new_player);
				
				new_player.GetModifiersManager().ActivateModifier(m_ModifierID); //Выдаем ему в новом потоке модификатор
				Print("Модификатор был выдан :: new_player.GetModifiersManager().ActivateModifier(m_ModifierID)");
				return;
			}
			else if(parent.IsInherited(NH_ArtContainerBase))//Если родитель относится к классу NH_ArtContainerBase
			{
				Print("EEItemLocationChanged :: else if(parent.IsInherited(NH_ArtContainerBase))" + parent.IsInherited(NH_ArtContainerBase));
				if(m_ModifiedPlayer)//При этом существует такой игрок, которому был выдан модификатор
				{
					Print("Модифицированный игрок существует");
					m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID); //Мы забираем его в новом потоке (сомнительно, не уверен что будет работать как надо)
					Print("Модификатор снят с игрока :: m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID)");
				}
				return;
			}
			else if(old_player)//Если существует игрок, которому был выдан модификатор И если новый игрок не является старым игроком, забираем модификатор
			{
				m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID);
				
				Print("Игрок выложил предмет из инвентаря, модификатор снят :: m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID)");
				return;
			}
		}
		
		
		/*if(oldLoc.GetParent()) // Если у старого предмета был родитель, тобишь не земля или не сила земли
			old_player = PlayerBase.Cast(oldLoc.GetParent().GetHierarchyRootPlayer()); // получаем игрока, у которого был предмет
		
		if(new_player) // если существует новый игрок
		{
			EntityAI parent = newLoc.GetParent();// получаем место где расположен наш арт
			
			Print("EntityAI parent = newLoc.GetItem():::: " + parent);
			
			Print(parent.IsInherited(NH_ArtContainerBase));
			
			if(parent.IsInherited(NH_ArtContainerBase)) // если место где расположен наш арт, является контейнером
			{
				new_player.GetModifiersManager().DeactivateModifier(m_ModifierID);
				return; // ретурним и не работаем с предметом
			}
			else if(old_player != new_player)
			{
				new_player.GetModifiersManager().ActivateModifier(m_ModifierID); // в противном случае, мы запускаем модификатор
				Print("new_player.GetModifiersManager().ActivateModifier(m_ModifierID)");
			}
		}
		
		if(old_player && (old_player != new_player)) // Если есть старый игрок и при этом старый игрок не является, новым игроком (чтобы откинуть вероятность ложного срабатывания на обычной смене положения предмета)
		{
			old_player.GetModifiersManager().DeactivateModifier(m_ModifierID);
			Print("old_player.GetModifiersManager().DeactivateModifier(m_ModifierID)");
			Print("old_player" + old_player.ToString() + " new_player" + new_player.ToString());
		}*/
		
		
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