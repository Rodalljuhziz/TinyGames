//
// Created by walcz on 17/06/2025.
//

#include <gtest/gtest.h>
#include "../Shifumi.h"
#include <../3rdparty/json.hpp>
#include <fstream>

using json = nlohmann::json;

TEST(ShifumiTest , setNumberOfRounds)
{
    Shifumi shifumi;
    const int error = shifumi.setRoundNumber(3);
    EXPECT_EQ(error, 0);
}

TEST(ShifumiTest, whoWins)
{
    int isWon;
    Shifumi shifumi;
    const std::string result = shifumi.isWinner(ShifumiChoice::Rock, isWon);
    EXPECT_NE(result, "");
}

TEST(ShifumiTest, setFilePathPlayerJson)
{
    Shifumi shifumi;
    const std::string setFilepath = "../test/";
    const int error = shifumi.setFilepathPlayerJson(setFilepath);
    EXPECT_EQ(error, 0);
}

TEST(ShifumiTest, getFilePathPlayerJson)
{
    Shifumi shifumi;
    const std::string setFilepath = "../test/";
    const int error = shifumi.setFilepathPlayerJson(setFilepath);
    EXPECT_EQ(error, 0);
    const std::string getFilepath = shifumi.getFilepathPlayerJson();
    EXPECT_EQ(setFilepath, getFilepath);
}

TEST(ShifumiTest, createPlayer)
{

    Shifumi shifumi;
    shifumi.setFilepathPlayerJson("../data");

    std::string name = "Marcel";

    std::filesystem::remove(std::filesystem::path("../data") / "players.json");

    const int error = shifumi.createPlayer(name);
    EXPECT_EQ(error, 0);

    std::ifstream file("../data/players.json");
    ASSERT_TRUE(file.is_open()) << "Fichier players.json introuvable après création.";

    json playerJSON;
    file >> playerJSON;

    ASSERT_TRUE(playerJSON.contains("PlayerList"));
    ASSERT_TRUE(playerJSON["PlayerList"].is_array());

    auto& list = playerJSON["PlayerList"];
    auto it = std::find(list.begin(), list.end(), name);
    EXPECT_NE(it, list.end()) << "Nom du joueur non trouvé dans le fichier JSON.";
}

TEST(ShifumiTest, deletePlayer)
{
    Shifumi shifumi;
    shifumi.setFilepathPlayerJson("../data");

    std::string name = "Marcel";

    std::filesystem::remove(std::filesystem::path("../data") / "players.json");

    int error = shifumi.createPlayer(name);
    EXPECT_EQ(error, 0);

    error = shifumi.deletePlayer(name);
    EXPECT_EQ(error, 0);

    std::ifstream file("../data/players.json");
    ASSERT_TRUE(file.is_open());

    json playerJSON;
    file >> playerJSON;

    ASSERT_TRUE(playerJSON.contains("PlayerList"));
    ASSERT_TRUE(playerJSON["PlayerList"].is_array());

    auto& list = playerJSON["PlayerList"];
    auto it = std::find(list.begin(), list.end(), name);
    EXPECT_EQ(it, list.end()) << "Le joueur existe toujours dans le fichier JSON après suppression.";
}

TEST(ShifumiTest, selectPlayer)
{
    Shifumi shifumi;
    shifumi.setFilepathPlayerJson("../data");

    std::string name = "Marcel";

    std::filesystem::remove(std::filesystem::path("../data") / "players.json");

    int error = shifumi.createPlayer(name);
    EXPECT_EQ(error, 0);

    error = shifumi.selectPlayer(name);
    EXPECT_EQ(error, 0);
}