#include "Util.h"

vector<float> Util::getWaveLen(){
    vector<float> wave;
    std::ifstream  data("wavelengths.csv");

    std::string line;
    std::getline(data,line);
    while(std::getline(data,line))
    {
        std::stringstream  lineStream(line);
        std::string        cell;

        while(std::getline(lineStream,cell,','))
        {
           //cout <<cell<<" | ";
           std::getline(lineStream,cell,',');
           wave.push_back(round(atof(cell.c_str())));
           //cout <<atof(cell.c_str());
        }
        //cout <<endl;
    }
    return wave;
}

vector<pair<float,float> > Util::getIntensity(vector<float> wave,map<int, vector<float> > m){
    vector<pair<float,float> >res;

    std::ifstream  data("intensities.csv");

    std::string line;
    int j=0;
    while(std::getline(data,line))
    {
        std::stringstream  lineStream(line);
        std::string        cell;
        int i=0;
        float X=0,Y=0,Z=0,x,y;
        while(std::getline(lineStream,cell,','))
        {
            i++;
            float intensity = atof(cell.c_str());
           // if(j==0 || j==1){
            //cout <<"Fator: "<<cell<<endl;
                if ( m.find(wave[i]) == m.end() ) {
             //       cout <<wave[i]<<" NAO"<<endl;
                } else {
                    X += m[wave[i]].at(0)*intensity;
                    Y += m[wave[i]].at(1)*intensity;
                    Z += m[wave[i]].at(2)*intensity;
                   // cout <<"X"<< X<<endl;
                  //  cout <<"Y"<< Y<<endl;
                 //   cout <<"Z"<< Z<<endl;
                   // cout <<m[wave[i]].at(0)<<endl;
           //       cout <<wave[i]<<" SIM"<<endl;
                }
           // }


            //cout << m[wave[i]].at(0) <<"|";

           //std::getline(lineStream,cell,',');
           //wave.push_back(round(atof(cell.c_str())));
           //cout <<atof(cell.c_str());
        }
       // cout <<j<<" linha: "<<i<<endl;
       // cout << X<<endl;
       // cout << Y<<endl;
       // cout << Z<<endl;
        x = X/(X+Y+Z);
        y = Y/(X+Y+Z);


        res.push_back(make_pair(x,y));
        j++;

        //cout <<endl;
    }


    return res;
}

map<int, vector<float> > Util::getCIE(){
    map<int, vector<float> > cie;
    std::ifstream  data("ciexyz31.csv");

    std::string line;
    while(std::getline(data,line))
    {
        std::stringstream  lineStream(line);
        std::string        cell;
        int key;
        for(int i=0;i<4;i++){
            std::getline(lineStream,cell,',');
            if(i==0){
                key = atof(cell.c_str());
            }else{
                cie[key].push_back(atof(cell.c_str()));
            }
           // cout <<cell<<" | ";
        }
        //while(std::getline(lineStream,cell,','))
        //{
           //cout <<cell<<" | ";
          // std::getline(lineStream,cell,',');
           //wave.push_back(round(atof(cell.c_str())));
           //cout <<atof(cell.c_str());
        //}
       // cout <<endl;
    }
    return cie;
}


pair<float,float> Util::desvio(vector<pair<float,float> > res){
    float sumX=0,sumY=0;
    float avgX,avgY;
    float varX=0,varY=0,terX,terY;
    float n = res.size();
    for(int i=0;i<n;i++){
        cout <<res.at(i).first<<endl;
        sumX += res.at(i).first;
        sumY += res.at(i).second;
    }
    avgX = sumX/n;
    avgY = sumY/n;
    cout << "Media X"<<avgX<<endl;
    for(int i=0;i<n;i++){
        terX = (res.at(i).first - avgX)*(res.at(i).first - avgX);
        terY = (res.at(i).second - avgY)*(res.at(i).second - avgY);
        varX += terX;
        varY += terY;
    }
    varX = varX/n;
    varY = varY/n;
    return make_pair(sqrt(varX),sqrt(varY));
}


void Util::writeResultToCsv(vector<pair<float,float> > res,pair<float,float> sd){
     float avgX=0,avgY=0;
     ofstream myfile;
      myfile.open ("outputColors.csv");
      myfile << "#Timestamp,x,y\n";
      for(int i=0;i<res.size();i++){
        myfile << i <<","<<res.at(i).first <<","<<res.at(i).second<<"\n";
        avgX += res.at(i).first/res.size();
        avgY += res.at(i).first/res.size();
      }
    myfile.close();

    myfile.open ("outputStandardDeviation.csv");
      myfile << "Average X,Standard deviation X,Average Y,Standard deviation Y\n";
      myfile << avgX <<","<<sd.first <<","<<avgY <<","<<sd.second<<"\n";

    myfile.close();
}

