modded class MiscGameplayFunctions
{
	static ref array<NH_art_Base> GetArtefacts(PlayerBase pl = NULL)
  	{
   	 	NHDebugPrint("MiscGameplayFunctions::GetArtefacts");
   	 	ref array<NH_art_Base> result;
    	
		result = new ref array<NH_art_Base>;

    	array<EntityAI> m_Objects = new array<EntityAI>;
    	int i   	= 0;
     	ItemBase    item;
      
     	if ( !pl ) return NULL;
	    pl.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, m_Objects );
	
     	for ( i = 0; i < m_Objects.Count(); i++ )
     	{
       		NH_art_Base art = NH_art_Base.Cast(m_Objects[i]);

       		if ( art ) result.Insert(art);
     	}
		
		return result;
	}
}