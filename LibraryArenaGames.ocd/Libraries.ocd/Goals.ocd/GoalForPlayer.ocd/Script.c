/**
	Library for a goal that is winnable by individual players.

	A faction in {@link Library_Goal_Configurable#index} corresponds to a player.

	@author Marky
 */

#include Library_Goal_Configurable


/* --- Goal description texts --- */

func GetDescription(int player)
{
	return GetGoalDescription(GetFactionByPlayer(player));
}

func GetShortDescription(int player)
{
	var score = GetFactionScore(GetFactionByPlayer(player));
	var target = GetWinScore();

	return Format("%d / %d", score, target);
}

/* --- Overloaded from configurable goal --- */

func DoWinRound(array factions)
{
	for (var faction in factions)
	{
		DoRoundScore(GetFaction(faction), 1);
	}
	_inherited(factions);
}
