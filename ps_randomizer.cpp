#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

//class for holding car data read from cars.bin
class car {
	public:
		string pvehicle;
		int tier;
		char canDrift;
};

class track {
	public:
		string trackname;
		string locale;
		int gametype;
};

//Global car/track data

//Car Data from disk
ifstream cardata;
//Holds car data split into when the cars inside are unlocked
//DlC is placed in a separate bucket in case the user doesn't have
//the DLC unlocked for *some* reason
vector<car> t0bucket, t1bucket, t2bucket, t3bucket, dlcbucket;
//Track Data from disk
ifstream trackdata;
//Holds track names split based on location
vector<track> autobahn_gd, autopolis, chicago_gd, ebisu, infineon, leipzig, mondello_park, nevada_gd, portland, shuto_gd, texas_speedway, willow_springs;

//Enables or disables DLC cars. Set to 1 by default.
int ALLOW_DLC = 1;

//Consts to note tier 1/2/3 when calling getRandomCar
//This lets us easily add an option to override vanilla
//tiers and pull cars from any bucket at any time
int t1 = 1;
int t2 = 2;
int t3 = 3;


//Returns a random car of the specified tier
//If tier_desired = 776, gets a car from a random tier
//If drift_desired != 'y', gets any car from the bucket regardless of drift ability
//Setting allow_dlc to 1 enables rolling DLC cars when tier_desired is set to 776
string getRandomCar(int tier_desired, char drift_desired, int allow_dlc)
{
	int randCarID;
	int tier = tier_desired;
	if (tier == 776)
	{
		tier = rand() % (4 + allow_dlc);
	}
	if (tier == 0)
	{
		randCarID = rand() % t0bucket.size();
		while (t0bucket[randCarID].canDrift != drift_desired && drift_desired == 'y')
		{
			randCarID = rand() % t0bucket.size();
		}
		return t0bucket[randCarID].pvehicle;
	}
	else if (tier == 1)
	{
		randCarID = rand() % t1bucket.size();
		while (t1bucket[randCarID].canDrift != drift_desired && drift_desired == 'y')
		{
			randCarID = rand() % t1bucket.size();
		}
		return t1bucket[randCarID].pvehicle;
	}
	else if (tier == 2)
	{
		randCarID = rand() % t2bucket.size();
		while (t2bucket[randCarID].canDrift != drift_desired && drift_desired == 'y')
		{
			randCarID = rand() % t2bucket.size();
		}
		return t2bucket[randCarID].pvehicle;
	}
	else if (tier == 3)
	{
		randCarID = rand() % t3bucket.size();
		while (t3bucket[randCarID].canDrift != drift_desired && drift_desired == 'y')
		{
			randCarID = rand() % t3bucket.size();
		}
		return t3bucket[randCarID].pvehicle;
	}
	else if (tier == 4)
	{
		randCarID = rand() % dlcbucket.size();
		while (dlcbucket[randCarID].canDrift != drift_desired && drift_desired == 'y')
		{
			randCarID = rand() % dlcbucket.size();
		}
		return dlcbucket[randCarID].pvehicle;
	}
}

//Returns a random track from the specified locale (776 = randomize locale)
string getRandomTrack(int racetype,int locale_desired)
{
	int randTrackID;
	int locale = locale_desired;
	if (locale == 776)
	{
		locale_desired = rand() % 12;
	}
	if (locale == 0)
	{
		randTrackID = rand() % autobahn_gd.size();
		// this sucks but it should keep race types consistent
		while (autobahn_gd[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % autobahn_gd.size();
		}
		return autobahn_gd[randTrackID].trackname;
	}
	else if (locale == 1)
	{
		randTrackID = rand() % autopolis.size();
		// this sucks but it should keep race types consistent
		while (autopolis[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % autopolis.size();
		}
		return autopolis[randTrackID].trackname;
	}
	else if (locale == 2)
	{
		randTrackID = rand() % chicago_gd.size();
		// this sucks but it should keep race types consistent
		while (chicago_gd[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % chicago_gd.size();
		}
		return chicago_gd[randTrackID].trackname;
	}
	else if (locale == 3)
	{
		randTrackID = rand() % ebisu.size();
		// this sucks but it should keep race types consistent
		while (ebisu[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % ebisu.size();
		}
		return ebisu[randTrackID].trackname;
	}
	else if (locale == 4)
	{
		randTrackID = rand() % infineon.size();
		// this sucks but it should keep race types consistent
		while (infineon[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % infineon.size();
		}
		return infineon[randTrackID].trackname;
	}
	else if (locale == 5)
	{
		randTrackID = rand() % leipzig.size();
		// this sucks but it should keep race types consistent
		while (leipzig[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % leipzig.size();
		}
		return leipzig[randTrackID].trackname;
	}
	else if (locale == 6)
	{
		randTrackID = rand() % mondello_park.size();
		// this sucks but it should keep race types consistent
		while (mondello_park[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % mondello_park.size();
		}
		return mondello_park[randTrackID].trackname;
	}
	else if (locale == 7)
	{
		randTrackID = rand() % nevada_gd.size();
		// this sucks but it should keep race types consistent
		while (nevada_gd[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % nevada_gd.size();
		}
		return nevada_gd[randTrackID].trackname;
	}
	else if (locale == 8)
	{
		randTrackID = rand() % portland.size();
		// this sucks but it should keep race types consistent
		while (portland[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % portland.size();
		}
		return portland[randTrackID].trackname;
	}
	else if (locale == 9)
	{
		randTrackID = rand() % shuto_gd.size();
		// this sucks but it should keep race types consistent
		while (shuto_gd[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % shuto_gd.size();
		}
		return shuto_gd[randTrackID].trackname;
	}
	else if (locale == 10)
	{
		randTrackID = rand() % texas_speedway.size();
		// this sucks but it should keep race types consistent
		while (texas_speedway[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % texas_speedway.size();
		}
		return texas_speedway[randTrackID].trackname;
	}
	else if (locale == 11)
	{
		randTrackID = rand() % willow_springs.size();
		// this sucks but it should keep race types consistent
		while (willow_springs[randTrackID].gametype != racetype)
		{
			randTrackID = rand() % willow_springs.size();
		}
		return willow_springs[randTrackID].trackname;
	}
}

int main(void)
{
	srand(time(NULL));
	//Randomization Seed
	int seed=0;
	//User input for menus
	int menuopt=0;
	//Randomizer preferences
	int prefs[4];
	cardata.open("cars.bin");
	trackdata.open("tracks.bin");
	//Load in car/track data
	cout<<"Loading car data...\n";
	car tmpcar;
	while(cardata.eof() == false)
	{
		//Car data is stored in the following format:
		//pvehicle name (used for modifying preset cars)
		//tier (when this car is unlocked)
		//drift ability ('n' = can't, 'y' = can)
		//comment / padding (;)
		//Read in car data
		cardata>>tmpcar.pvehicle;
		cardata>>tmpcar.tier;
		cardata>>tmpcar.canDrift;
		if (tmpcar.tier == 0)
		{
			t0bucket.push_back(tmpcar);
			t1bucket.push_back(tmpcar);
		}
		else if (tmpcar.tier == 1)
		{
			t1bucket.push_back(tmpcar);
		}
		else if (tmpcar.tier == 2)
		{
			t2bucket.push_back(tmpcar);
		}
		else if (tmpcar.tier == 3)
		{
			t3bucket.push_back(tmpcar);
		}
		else
		{
			dlcbucket.push_back(tmpcar);
		}
		//read in padding char, we can stick this in the pvehicle var
		//as we've already pushed its data into the respective car bin
		cout<<tmpcar.pvehicle<<"\n";
		cardata>>tmpcar.pvehicle;
		//cardata.ignore(0,' ');
	}
	cout<<"\nLoading track data...\n";
	track tmptrack;
	while(trackdata.eof() == false)
	{
		//Track data is stored in the following format:
		//locale (where this track is located)
		//gametype (0 = grip, 1 = speed challenge, 2 = drift, 3 = drag)
		//trackname (used for modifying track layout)
		//comment / padding (;)
		//Read in track data
		trackdata>>tmptrack.locale;
		trackdata>>tmptrack.gametype;
		trackdata>>tmptrack.trackname;
		if (tmptrack.locale == "autobahn")
		{
			autobahn_gd.push_back(tmptrack);
		}
		else if (tmptrack.locale == "autopolis")
		{
			autopolis.push_back(tmptrack);
		}
		else if (tmptrack.locale == "chicago_gd")
		{
			chicago_gd.push_back(tmptrack);
		}
		else if (tmptrack.locale == "ebisu")
		{
			ebisu.push_back(tmptrack);
		}
		else if (tmptrack.locale == "infineon")
		{
			infineon.push_back(tmptrack);
		}
		else if (tmptrack.locale == "leipzig")
		{
			leipzig.push_back(tmptrack);
		}
		else if (tmptrack.locale == "mondello_park")
		{
			mondello_park.push_back(tmptrack);
		}
		else if (tmptrack.locale == "nevada_gd")
		{
			nevada_gd.push_back(tmptrack);
		}
		else if (tmptrack.locale == "portland")
		{
			portland.push_back(tmptrack);
		}
		else if (tmptrack.locale == "shuto_gd")
		{
			shuto_gd.push_back(tmptrack);
		}
		else if (tmptrack.locale == "texas_speedway")
		{
			texas_speedway.push_back(tmptrack);
		}
		else if (tmptrack.locale == "willow_springs")
		{
			willow_springs.push_back(tmptrack);
		}
		else
		{
			cout<<"\n\nFATAL ERROR: Invalid track locale!!\n\n";
			cout<<"Dumping some useful info...\n";
			cout<<"Track Name: "<<tmptrack.trackname<<"\n";
			cout<<"Locale: "<<tmptrack.locale<<"\n";
			return 0;
		}
		cout<<tmptrack.trackname<<"\n";
		//read in padding char, we can stick this in the pvehicle var
		//as we've already pushed its data into the respective car bin
		trackdata.ignore(256,'\n');
		trackdata.ignore(256,'\n');
	}
	cout<<"\n\nData loaded successfully.\n\n\nWelcome to the ProStreet Randomizer!\nWould you like to load your previously saved settings?\n(0 = NO, 1 = YES)\n";
	cin>>menuopt;
	if (menuopt != 0)
	{
		ifstream savedprefs;
		savedprefs.open("settings.ini");
		for (int x=0;x < 4;x++)
		{
			savedprefs>>prefs[x];
		}
		savedprefs.close();
	}
	else
	{
		//Starter car randomization
		cout<<"\nPlease select your randomization options by inputting the number next to the option you want to use.";
		cout<<"\n\nSTARTER CAR";
		cout<<"\nSet how you want to randomize the starter car given in the prolouge.";
		cout<<"\n0 = No Randomization: You get Ryan Cooper's 240SX as in the vanilla game";
		cout<<"\n1 = D-Day Only: Randomizes between the cars seen in the prolouge - 240SX, Corolla, and Civic Hatch";
		cout<<"\n2 = Tier 1 Only: Randomizes between cars available before React Team Sessions";
		cout<<"\n3 = Anything Goes: Randomizes to any car in the game, ignoring tiers.";
		cout<<"\nInput Selection: ";
		cin>>menuopt;
		while (menuopt > 3 || menuopt < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000000, '\n');
			cout<<"Invalid Selection. Please try again.\n";
			cin>>menuopt;
		}
		prefs[0] = menuopt;
		//Challenge Weekend preset car randomization
		cout<<"\n\nCHALLENGE WEEKENDS / PINK SLIPS";
		cout<<"\nSet how to randomize the cars used for Challenge Weekends.\nRandomized cars will be kept to the same tier as the original car";
		cout<<"\n0 = No Randomization: Keeps all preset cars the same as vanilla";
		cout<<"\n1 = Randomize Player: Randomizes just your car";
		cout<<"\n2 = Randomize Opponents: Randomizes just the opponents' cars";
		cout<<"\n3 = Randomize w/ Even Field: Randomizes the car everyone uses";
		cout<<"\n4 = Pure Random: Player and opponents drive different, randomized cars";
		cout<<"\n5 = Anarchy: Randomizes opponents, but you bring your own cars! Disables reward cars.";
		cout<<"\nInput Selection: ";
		cin>>menuopt;
		while (menuopt > 5 || menuopt < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000000, '\n');
			cout<<"Invalid Selection. Please try again.\n";
			cin>>menuopt;
		}
		prefs[1] = menuopt;
		//Race day track randomization
		//dis no worko :(
		/*cout<<"\n\nRACE DAYS";
		cout<<"\nSet how to randomize the races for each race day.";
		cout<<"\n0 = No Randomization: Keeps all race days the same as vanilla";
		cout<<"\n1 = Randomize In Locale: Randomizes race days, but only with other races from the same location";
		cout<<"\n2 = World Tour: Randomize race days with races from any location";
		cout<<"\nInput Selection: ";
		cin>>menuopt;
		while (menuopt > 2 || menuopt < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000000, '\n');
			cout<<"Invalid Selection. Please try again.\n";
			cin>>menuopt;
		}
		prefs[2] = menuopt;*/
		//Repair Marker randomization
		/*
		cout<<"\n\nREWARD MARKERS";
		cout<<"\nSet how to randomize reward markers."
		cout<<"\n0 = No Randomization: Reward Cards appear as normal"
		cout<<"\n1 = Randomize Repair Markers: Turns the Repair and Total Repair markers into something else!"*/
		//Kings randomization
		cout<<"\n\nKINGS";
		cout<<"\nSet how to randomize the cars driven by the Kings.";
		cout<<"\n0 = No Randomization: Let Nate Denver keep his death machine";
		cout<<"\n1 = Randomize In Tier 3: Randomizes to any car unlocked after Super Promotion (Viper, Zonda, etc)";
		cout<<"\n2 = Pure Random: Randomize to anything! (Karol Monroe may not be able to wheelie)";
		cout<<"\n3 = Randomize In Tier 3 (No Ryo): Same as 1, but won't affect Ryo";
		cout<<"\n4 = Pure Random (No Ryo): Same as 2, but won't affect Ryo";
		cout<<"\nInput Selection: ";
		cin>>menuopt;
		while (menuopt > 2 || menuopt < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000000, '\n');
			cout<<"Invalid Selection. Please try again.\n";
			cin>>menuopt;
		}
		prefs[3] = menuopt;
		cout<<"\n\nCHAOS MODE";
		cout<<"\nLet's get crazy.";
		cout<<"\n0 = Off: Randomized cars will stay within the same tier";
		cout<<"\n1 = On: Randomized cars can become anything from any tier, including DLC cars\nThis overrides tier restrictions on the Kings and starter car if previously set";
		cout<<"\nInput Selection: ";
		cin>>menuopt;
		while (menuopt > 1 || menuopt < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000000, '\n');
			cout<<"Invalid Selection. Please try again.\n";
			cin>>menuopt;
		}
		prefs[2] = menuopt;
		//Save preferences
		cout<<"\n\nWould you like to save your settings?";
		cout<<"\n0 = Don't Save";
		cout<<"\n1 = Save";
		cout<<"\nInput Selection: ";
		cin>>menuopt;
		while (menuopt > 1 || menuopt < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000000, '\n');
			cout<<"Invalid Selection. Please try again.\n";
		}
		if (menuopt == 1)
		{
			ofstream savedPrefs;
			savedPrefs.open("settings.ini");
			for (int x=0;x < 4;x++)
			{
				savedPrefs<<prefs[x]<<"\n";
			}
			savedPrefs.close();
			cout<<"\nSettings saved to 'settings.ini'.";
		}
	}
	cout<<"\nRandomizing...";
	ofstream modscript;
	modscript.open("randomizer.nfsms");
	//Chaos Mode
	if (prefs[2] == 1)
	{
		t1 = 776;
		t2 = 776;
		t3 = 776;
	}
	//Randomize starter car
	if (prefs[0] != 0)
	{
		if (prefs[0] == 1)
		{
			modscript<<"update_field presetride player_d_day CarType Collection "<<getRandomCar(0,'n',0)<<"\n";
		}
		else if (prefs[0] == 2)
		{
			modscript<<"update_field presetride player_d_day CarType Collection "<<getRandomCar(t1,'n',0)<<"\n";
		}
		else
		{
			modscript<<"update_field presetride player_d_day CarType Collection "<<getRandomCar(776,'n',ALLOW_DLC)<<"\n";
		}
	}
	//Randomize Challenge Raceday preset cars
	if (prefs[1] != 0)
	{
		string player_randocar[3];
		string player_randocar_drift[3];
		string comp_randocar[3];
		string comp_randocar_drift[3];
		//Randomize Player | Pure Random (player car)
		if (prefs[1] == 1 || prefs[1] == 4)
		{
			//Insert random cars
			//Infineon t3
			modscript<<"update_field presetride ch_t3_inf_drag CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_inf_drift CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_inf_grip2 CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_inf_grip CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Nevada t1 (orig: cobalt, civic hatch, golf)
			modscript<<"update_field presetride p_ch_t1_nvd_drag CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_nvd_drag2 CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_nvd_grip CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			//Texas t1
			modscript<<"update_field presetride p_ch_t1_tx_drag CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_tx_drift CarType Collection "<<getRandomCar(t1,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_tx_grip CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_tx_grip2 CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			//Willow Springs t1
			modscript<<"update_field presetride p_ch_t1_willow_drag CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_willow_drag2 CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_willow_drift CarType Collection "<<getRandomCar(t1,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t1_willow_grip CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Autopolis t2
			modscript<<"update_field presetride p_ch_t2_autop_drift CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t2_autop_drift2 CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t2_autop_grip CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Autopolis t2 CE
			modscript<<"update_field presetride p_ch_t2_ce_autop_drift CarType Collection "<<getRandomCar(t1,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t2_ce_autop_grip CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t2_ce_autop_grip2 CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			//Ebisu t2
			modscript<<"update_field presetride p_ch_t2_eb_drift CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t2_eb_grip CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t2_eb_sc CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t2_eb_sc2 CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Autobahn t3
			modscript<<"update_field presetride p_ch_t3_autob_drift CarType Collection "<<getRandomCar(t3,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t3_autob_grip CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t3_autob_sc CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t3_autob_sc2 CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Nevada t3
			modscript<<"update_field presetride p_ch_t3_nev_drag CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_drift CarType Collection "<<getRandomCar(t3,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_grip CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_sc CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_sc2 CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
		}
		//Randomize Opponents | Pure Random (opp. car) | Anarchy
		if (prefs[1] == 2 || prefs[1] == 4 || prefs[1] == 5)
		{
			//Portland t1
			modscript<<"update_field presetride ch_t1_ptl_drag_civichb CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_ptl_drag_mustgt CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_ptl_ptl_grip_civichb CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			//Texas t1
			modscript<<"update_field presetride ch_t1_tx_drag_gti CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_tx_drift_350z CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_tx_grip_gti CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_tx_grip_350z CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Willow Springs t1
			modscript<<"update_field presetride ch_t1_willow_drag_chevelle CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_willow_drift_chevelle CarType Collection "<<getRandomCar(t1,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_willow_drift_is350 CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t1_willow_grip_is350 CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Autopolis t2 (booster pack)
			modscript<<"update_field presetride ch_t2_autop_drift_s15 CarType Collection "<<getRandomCar(t1,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t2_autop_drift_solstice CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t2_autop_grip_s15 CarType Collection "<<getRandomCar(t1,'n',ALLOW_DLC)<<"\n";
			//Ebisu t2
			modscript<<"update_field presetride ch_t2_ebisu_drift_supra CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t2_ebisu_grip_bmwm3 CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t2_ebisu_sc_bmwm3 CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t2_ebisu_sc_supra CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//"Mondello Park" (Autopolis t2)
			modscript<<"update_field presetride ch_t2_mond_drift_g35 CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t2_mond_drift_gto CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t2_mond_grip_gto CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Infineon t3
			modscript<<"update_field presetride ch_t3_infineon_drag_cayman CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_infineon_drift_nsx CarType Collection "<<getRandomCar(t2,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_infineon_grip_cayman CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_infineon_grip_nsx CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			//Nevada t3
			modscript<<"update_field presetride ch_t3_nevada_drag_z06 CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_drift_z06 CarType Collection "<<getRandomCar(t3,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_grip_rs4 CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_sc_rs4 CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_sc_z06 CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			//Autobahn t3
			modscript<<"update_field presetride ch_t3_autob_drift_viper CarType Collection "<<getRandomCar(t3,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_autob_grip_skyline CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_autob_sc_skyline CarType Collection "<<getRandomCar(t2,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride ch_t3_autob_sc_viper CarType Collection "<<getRandomCar(t3,'y',ALLOW_DLC)<<"\n";
		}
		if (prefs[1] == 3)
		{
			//Insert random cars
			//Infineon t3
			string t3_inf_drag = getRandomCar(t2,'n',ALLOW_DLC);
			string t3_inf_drift = getRandomCar(t2,'y',ALLOW_DLC);
			string t3_inf_grip2 = getRandomCar(t2,'n',ALLOW_DLC);
			string t3_inf_grip = getRandomCar(t2,'n',ALLOW_DLC);
			modscript<<"update_field presetride ch_t3_inf_drag CarType Collection "<<t3_inf_drag<<"\n";
			modscript<<"update_field presetride ch_t3_inf_drift CarType Collection "<<t3_inf_drift<<"\n";
			modscript<<"update_field presetride ch_t3_inf_grip2 CarType Collection "<<t3_inf_grip2<<"\n";
			modscript<<"update_field presetride ch_t3_inf_grip CarType Collection "<<t3_inf_grip<<"\n";
			//Nevada t1 (orig: cobalt, civic hatch, golf)
			string t1_nvd_drag = getRandomCar(t1,'n',ALLOW_DLC);
			string t1_nvd_drag2 = getRandomCar(t1,'n',ALLOW_DLC);
			string t1_nvd_grip = getRandomCar(t1,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t1_nvd_drag CarType Collection "<<t1_nvd_drag<<"\n";
			modscript<<"update_field presetride p_ch_t1_nvd_drag2 CarType Collection "<<t1_nvd_drag2<<"\n";
			modscript<<"update_field presetride p_ch_t1_nvd_grip CarType Collection "<<t1_nvd_grip<<"\n";
			//Texas t1
			string t1_tx_drag = getRandomCar(t1,'n',ALLOW_DLC);
			string t1_tx_drift = getRandomCar(t2,'y',ALLOW_DLC);
			string t1_tx_grip = getRandomCar(t1,'n',ALLOW_DLC);
			string t1_tx_grip2 = getRandomCar(t2,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t1_tx_drag CarType Collection "<<t1_tx_drag<<"\n";
			modscript<<"update_field presetride p_ch_t1_tx_drift CarType Collection "<<t1_tx_drift<<"\n";
			modscript<<"update_field presetride p_ch_t1_tx_grip CarType Collection "<<t1_tx_grip<<"\n";
			modscript<<"update_field presetride p_ch_t1_tx_grip2 CarType Collection "<<t1_tx_grip2<<"\n";
			//Willow Springs t1
			string t1_willow_drag = getRandomCar(t1,'n',ALLOW_DLC);
			string t1_willow_drag2 = getRandomCar(t2,'n',ALLOW_DLC);
			string t1_willow_drift = getRandomCar(t1,'y',ALLOW_DLC);
			string t1_willow_grip = getRandomCar(t2,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t1_willow_drag CarType Collection "<<t1_willow_drag<<"\n";
			modscript<<"update_field presetride p_ch_t1_willow_drag2 CarType Collection "<<t1_willow_drag2<<"\n";
			modscript<<"update_field presetride p_ch_t1_willow_drift CarType Collection "<<t1_willow_drift<<"\n";
			modscript<<"update_field presetride p_ch_t1_willow_grip CarType Collection "<<t1_willow_grip<<"\n";
			//Autopolis t2
			string t2_autop_drift = getRandomCar(t2,'y',ALLOW_DLC);
			string t2_autop_drift2 = getRandomCar(t2,'y',ALLOW_DLC);
			string t2_autop_grip = getRandomCar(t2,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t2_autop_drift CarType Collection "<<t2_autop_drift<<"\n";
			modscript<<"update_field presetride p_ch_t2_autop_drift2 CarType Collection "<<t2_autop_drift2<<"\n";
			modscript<<"update_field presetride p_ch_t2_autop_grip CarType Collection "<<t2_autop_grip<<"\n";
			//Autopolis t2 CE
			string t2_autop_ce_drift = getRandomCar(t1,'y',ALLOW_DLC);
			string t2_autop_ce_grip = getRandomCar(t1,'n',ALLOW_DLC);
			string t2_autop_ce_grip2 = getRandomCar(t2,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t2_ce_autop_drift CarType Collection "<<t2_autop_ce_drift<<"\n";
			modscript<<"update_field presetride p_ch_t2_ce_autop_grip CarType Collection "<<t2_autop_ce_grip<<"\n";
			modscript<<"update_field presetride p_ch_t2_ce_autop_grip2 CarType Collection "<<t2_autop_ce_grip2<<"\n";
			//Ebisu t2
			string t2_eb_drift = getRandomCar(t2,'y',ALLOW_DLC);
			string t2_eb_grip = getRandomCar(t2,'n',ALLOW_DLC);
			string t2_eb_sc = getRandomCar(t2,'n',ALLOW_DLC);
			string t2_eb_sc2 = getRandomCar(t2,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t2_eb_drift CarType Collection "<<t2_eb_drift<<"\n";
			modscript<<"update_field presetride p_ch_t2_eb_grip CarType Collection "<<t2_eb_grip<<"\n";
			modscript<<"update_field presetride p_ch_t2_eb_sc CarType Collection "<<t2_eb_sc<<"\n";
			modscript<<"update_field presetride p_ch_t2_eb_sc2 CarType Collection "<<t2_eb_sc2<<"\n";
			//Autobahn t3
			string t3_autob_drift = getRandomCar(t3,'y',ALLOW_DLC);
			string t3_autob_grip = getRandomCar(t3,'n',ALLOW_DLC);
			string t3_autob_sc = getRandomCar(t3,'n',ALLOW_DLC);
			string t3_autob_sc2 = getRandomCar(t3,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t3_autob_drift CarType Collection "<<t3_autob_drift<<"\n";
			modscript<<"update_field presetride p_ch_t3_autob_grip CarType Collection "<<t3_autob_grip<<"\n";
			modscript<<"update_field presetride p_ch_t3_autob_sc CarType Collection "<<t3_autob_sc<<"\n";
			modscript<<"update_field presetride p_ch_t3_autob_sc2 CarType Collection "<<t3_autob_sc2<<"\n";
			//Nevada t3
			string t3_nev_drag = getRandomCar(t3,'n',ALLOW_DLC);
			string t3_nev_drift = getRandomCar(t3,'y',ALLOW_DLC);
			string t3_nev_grip = getRandomCar(t3,'n',ALLOW_DLC);
			string t3_nev_sc = getRandomCar(t3,'n',ALLOW_DLC);
			string t3_nev_sc2 = getRandomCar(t3,'n',ALLOW_DLC);
			modscript<<"update_field presetride p_ch_t3_nev_drag CarType Collection "<<t3_nev_drag<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_drift CarType Collection "<<t3_nev_drift<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_grip CarType Collection "<<t3_nev_grip<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_sc CarType Collection "<<t3_nev_sc<<"\n";
			modscript<<"update_field presetride p_ch_t3_nev_sc2 CarType Collection "<<t3_nev_sc2<<"\n";
			//
			//CPU CARS
			//
			//Portland t1
			modscript<<"update_field presetride ch_t1_ptl_drag_civichb CarType Collection "<<t1_nvd_drag<<"\n";
			modscript<<"update_field presetride ch_t1_ptl_drag_mustgt CarType Collection "<<t1_nvd_drag2<<"\n";
			modscript<<"update_field presetride ch_t1_ptl_grip_civichb CarType Collection "<<t1_nvd_grip<<"\n";
			//Texas t1
			modscript<<"update_field presetride ch_t1_tx_drag_gti CarType Collection "<<t1_tx_drag<<"\n";
			modscript<<"update_field presetride ch_t1_tx_drift_350z CarType Collection "<<t1_tx_drift<<"\n";
			modscript<<"update_field presetride ch_t1_tx_grip_gti CarType Collection "<<t1_tx_grip<<"\n";
			modscript<<"update_field presetride ch_t1_tx_grip_350z CarType Collection "<<t1_tx_grip2<<"\n";
			//Willow Springs t1
			modscript<<"update_field presetride ch_t1_willow_drag_chevelle CarType Collection "<<t1_willow_drag<<"\n";
			modscript<<"update_field presetride ch_t1_willow_drift_chevelle CarType Collection "<<t1_willow_drift<<"\n";
			modscript<<"update_field presetride ch_t1_willow_drift_is350 CarType Collection "<<t1_willow_drift<<"\n";
			modscript<<"update_field presetride ch_t1_willow_grip_is350 CarType Collection "<<t1_willow_grip<<"\n";
			//Autopolis t2 (booster pack)
			modscript<<"update_field presetride ch_t2_autop_drift_s15 CarType Collection "<<t2_autop_ce_drift<<"\n";
			modscript<<"update_field presetride ch_t2_autop_drift_solstice CarType Collection "<<t2_autop_ce_drift<<"\n";
			modscript<<"update_field presetride ch_t2_autop_grip_s15 CarType Collection "<<t2_autop_ce_grip<<"\n";
			//Ebisu t2
			modscript<<"update_field presetride ch_t2_ebisu_drift_supra CarType Collection "<<t2_eb_drift<<"\n";
			modscript<<"update_field presetride ch_t2_ebisu_grip_bmwm3 CarType Collection "<<t2_eb_grip<<"\n";
			modscript<<"update_field presetride ch_t2_ebisu_sc_bmwm3 CarType Collection "<<t2_eb_sc<<"\n";
			modscript<<"update_field presetride ch_t2_ebisu_sc_supra CarType Collection "<<t2_eb_sc2<<"\n";
			//"Mondello Park" (Autopolis t2)
			modscript<<"update_field presetride ch_t2_mond_drift_g35 CarType Collection "<<t2_autop_drift<<"\n";
			modscript<<"update_field presetride ch_t2_mond_drift_gto CarType Collection "<<t2_autop_drift2<<"\n";
			modscript<<"update_field presetride ch_t2_mond_grip_gto CarType Collection "<<t2_autop_grip<<"\n";
			//Infineon t3
			modscript<<"update_field presetride ch_t3_infineon_drag_cayman CarType Collection "<<t3_inf_drag<<"\n";
			modscript<<"update_field presetride ch_t3_infineon_drift_nsx CarType Collection "<<t3_inf_drift<<"\n";
			modscript<<"update_field presetride ch_t3_infineon_grip_cayman CarType Collection "<<t3_inf_grip<<"\n";
			modscript<<"update_field presetride ch_t3_infineon_grip_nsx CarType Collection "<<t3_inf_grip2<<"\n";
			//Nevada t3
			modscript<<"update_field presetride ch_t3_nevada_drag_z06 CarType Collection "<<t3_nev_drag<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_drift_z06 CarType Collection "<<t3_nev_drift<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_grip_rs4 CarType Collection "<<t3_nev_grip<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_sc_rs4 CarType Collection "<<t3_nev_sc<<"\n";
			modscript<<"update_field presetride ch_t3_nevada_sc_z06 CarType Collection "<<t3_nev_sc2<<"\n";
			//Autobahn t3
			modscript<<"update_field presetride ch_t3_autob_drift_viper CarType Collection "<<t3_autob_drift<<"\n";
			modscript<<"update_field presetride ch_t3_autob_grip_skyline CarType Collection "<<t3_autob_grip<<"\n";
			modscript<<"update_field presetride ch_t3_autob_sc_skyline CarType Collection "<<t3_autob_sc2<<"\n";
			modscript<<"update_field presetride ch_t3_autob_sc_viper CarType Collection "<<t3_autob_sc<<"\n";			
		}
		if (prefs[1] == 5)
		{
			modscript<<"update_field gameplay prostreet_career/hubs/mk_2_1 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/ws_1_3 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/an_3_1 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/as_2_4 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/eu_2_2 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/in_3_3 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/na_3_3 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/pd_1_1 ChallengeHub False\n";
			modscript<<"update_field gameplay prostreet_career/hubs/pd_1_1 ChallengeHub True\n";
		}
	}
	//Randomize Tracks
	/*if (prefs[2] != 0)
	{
		
	}*/
	//Randomize Kings
	if (prefs[3] != 0)
	{
		if (prefs[3] == 1 || 3)
		{
			modscript<<"update_field presetride drag_king CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride drift_king CarType Collection "<<getRandomCar(t3,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride grip_king CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride sc_king CarType Collection "<<getRandomCar(t3,'n',ALLOW_DLC)<<"\n";
			if (prefs[3] == 1)
			{
				string ryo = getRandomCar(t3,'y',ALLOW_DLC);
				modscript<<"update_field presetride showdown_king_final_drag CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_final_drift CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_final_grip CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_final_sc CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_playable CarType Collection "<<ryo<<"\n";
			}
		}
		else if (prefs[3] == 2 || 4)
		{
			modscript<<"update_field presetride drag_king CarType Collection "<<getRandomCar(776,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride drift_king CarType Collection "<<getRandomCar(776,'y',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride grip_king CarType Collection "<<getRandomCar(776,'n',ALLOW_DLC)<<"\n";
			modscript<<"update_field presetride sc_king CarType Collection "<<getRandomCar(776,'n',ALLOW_DLC)<<"\n";
			if (prefs[3] == 2)
			{
				string ryo = getRandomCar(776,'y',ALLOW_DLC);
				modscript<<"update_field presetride showdown_king_final_drag CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_final_drift CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_final_grip CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_final_sc CarType Collection "<<ryo<<"\n";
				modscript<<"update_field presetride showdown_king_playable CarType Collection "<<ryo<<"\n";
			}
		}
	}
	cout<<"\nRandomizer script complete! Use NFS-VLTED to install.\n";
	cout<<"\nTo see what was randomized, open randomizer.nfsms with a text editor.\n";
	return 0;
}
