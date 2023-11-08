#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"

using namespace std;
//*******************************************************************
//Methods:
void simpleSortTotal(LinkedList &l, Airport a);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
double distanceAust(double lat1d, double lon1d);
//*******************************************************************
//Constants:
const double AUSlong = -97.66989899;
const double AUSlat = 30.19449997;
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0
//*******************************************************************
//Conversions:

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

double distanceAUS(double lat1d, double lon1d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(AUSlat);
  lon2r = deg2rad(AUSlong);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}
//*******************************************************************
//Main:
int main()
{
    ifstream infile;
    int i=0;
    char cNum[20];
    LinkedList airportList;
    int airportCount;
    string line;
    int stringLine = 1;
    //Airport* a[13500];
    infile.open ("airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
        string iDontLikeOpeningFiles;
        getline(infile, iDontLikeOpeningFiles);
        //int c=0;
        while (getline(infile,line))
        {
          stringLine++;
          if(stringLine<=22338)
          {
            Airport newAirport;
            int comma1 = line.find(",");
            int comma2 = line.find(",", comma1+1); //from worlddata
            newAirport.status = line.substr(comma1+1,comma2-comma1-1);
            int comma3 = line.find(",", comma2+1);
            newAirport.name = line.substr(comma2+1,comma3-comma2-1);
            int comma4 = line.find(",", comma3+1);
            newAirport.longitude = stod(line.substr(comma3+1, comma4-comma3-1));
            int comma5 = line.find(",", comma4+1);
            newAirport.latitude = stod(line.substr(comma4+1, comma5-comma4-1));
            int comma6 = line.find(",", comma5+1);
            int comma7 = line.find(",", comma6+1);
            int comma8 = line.find(",", comma7+1);
            int comma9 = line.find(",", comma8+1);
            int comma10 = line.find(",", comma9+1);
            int comma11 = line.find(",", comma10+1);
            int comma12 = line.find(",", comma11+1);
            int comma13 = line.find("\n", comma11+1);
            airportList.add(newAirport);
            /*
            infile.getline(newAirport.code, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            newAirport.longitude = atof(cNum);
            infile.getline(cNum, 256, ',');
            newAirport.latitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportList.add(newAirport);
             cout << "hio" << endl;*/
          }
          else{
            break;
          }
        }
        //airportCount = c-1;
        infile.close();
        Node *current = airportList.get(0);

      double md = 0.0;
      Airport far;
      cout << "List within 100 miles of AUS:" <<endl;

      /*int tempS = airportList.size();
      for(int i=0;i<tempS;i++)
        {
          if(airportList.get(i)->data.status=="closed")
          {
            cout << "choo choo" << endl;
            airportList.remove(i);
          }
        }*/
      
      //new list with only active FAA airports
/*      for(int i=0;i<airportList.size();i++){
        bool temp=true;
        while(temp)
          {
            
          }
      }*/
      
      for(int i=0;i<airportList.size();i++)
        {
          Airport currentA = airportList.get(i)->data;
          double currentD = distanceAUS(currentA.latitude, currentA.longitude);
          if(currentD<=100.0)
          {
            cout << currentA.name << endl;
          }
          if(currentD>md)
          {
            md = currentD;
            far = currentA;
          }
          if(currentA.status=="closed")
          {
            airportList.remove(i);
          }
        }
      cout << "Farthest: " << far.name << endl;

              
         /*for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }*/
    }
    else
    {
        cout << "Error opening file";
    }
  cout << "here" << endl;
}





/*if (!(c % 1000))
  cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;*/

/*
if (!(c % 1000))
{

  Provide sort routine on linked list
void simpleSortTotal()
{
}
  cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
  cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
}
*/     
//i++ ;
//c++;