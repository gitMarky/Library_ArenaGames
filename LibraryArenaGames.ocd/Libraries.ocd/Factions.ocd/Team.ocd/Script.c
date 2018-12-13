/**
	Faction representation: A faction corresponds to a team.

	@author Marky
 */

func GetFactionCount()
{
	if (Library_Faction_OnlyActiveTeams)
	{
		return GetLength(GetActiveTeams());
	}
	else
	{
		return GetTeamCount();
	}
}

func GetFactionByIndex(int index)
{
	if (Library_Faction_OnlyActiveTeams)
	{
		return GetActiveTeams()[index];
	}
	else
	{
		return GetTeamByIndex(index);
	}
}

func GetFactionByPlayer(int player)
{
	return GetPlayerTeam(player);
}

func GetFactionColor(int team)
{
	if (GetTeamConfig(TEAM_AutoGenerateTeams) && GetTeamPlayerCount(team) == 1)
	{
		return GetPlayerColor(GetTeamPlayer(team, 0));
	}
	else
	{
		return GetTeamColor(team);
	}
}

func GetFactionName(int team)
{
	return GetTeamName(team);
}

local Library_Faction_OnlyActiveTeams = true;