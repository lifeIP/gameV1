#pragma once
class DataRecording
{
private:
    std::experimental::filesystem::path workdir;
    std::experimental::filesystem::path workdirplas;
public:
    std::experimental::filesystem::path* get_workdir() {
        return &workdir;
    }
    DataRecording() {
        workdir = std::experimental::filesystem::current_path();
    }
    void overwriting(const sf::Vector2u* coord, std::experimental::filesystem::path* workdir, std::string* folder, std::string* fileName, unsigned int* recpos, unsigned int* tile_ID) {
        workdirplas = *workdir / *folder / *fileName;
        std::ofstream fout(workdirplas, std::ios::binary);
        //recording something+
        fout << std::to_string(*tile_ID) << std::endl;
        //recording something-
        fout.close();
    }
    //jackal writing and reading+
    void record(const sf::Vector2u* coord, std::experimental::filesystem::path* workdir, std::string* folder, unsigned int* tile_ID) {
        std::string name = std::to_string(coord->x) + "." + std::to_string(coord->y);
        workdirplas = *workdir / *folder / name;
        std::ofstream fout(workdirplas, std::ios::binary);
        //recording something+
        fout << std::to_string(*tile_ID) << std::endl;
        //recording something-
        fout.close();
    }
    void read(const sf::Vector2u* coord, std::experimental::filesystem::path* workdir, std::string* folder, unsigned int* tile_ID) {
        std::string name = std::to_string(coord->x) + "." + std::to_string(coord->y);
        workdirplas = *workdir / *folder / name;
        char str_in[50];
        std::ifstream fin(workdirplas, std::ios::binary);
        if (fin.is_open())
        {
            for (int i = 0; !fin.eof(); i++) {
                fin.getline(str_in, sizeof(str_in));
                if (i == 0) {
                    *tile_ID = std::atoi(str_in);
                }
                else if (i == 1) {

                }
                else if (i == 2) {

                }
                else if (i == 3) {

                }
                else if (i == 4) {

                }
                else if (i == 5) {

                }
                else if (i == 6) {

                }
                else if (i == 7) {

                }
                else if (i == 8) {

                }
                else if (i == 9) {

                }
            }
        }
        fin.close();
    }
    //jackal writing and reading-
};