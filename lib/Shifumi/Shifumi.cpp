//
// Created by walcz on 17/06/2025.
//

#include "Shifumi.h"
#include "ShifumiUtils.h"
#include <random>
#include <fstream>
#include <filesystem>
#include <../3rdparty/json.hpp>
#include <glog/logging.h>

using json = nlohmann::json;

Shifumi::Shifumi()
{
    m_filepathPlayerJson = "../data/";
    m_playerSelected = "";
}

ShifumiChoice Shifumi::intToShifumiChoice(const int choice)
{
    switch (choice)
    {
        case 1: return ShifumiChoice::Rock;
        case 2: return ShifumiChoice::Paper;
        case 3: return ShifumiChoice::Scissors;
        default: return ShifumiChoice::Rock; // Default to Rock if invalid choice
    }
}

int Shifumi::getRoundNumber() const
{
    return m_numberOfRounds;
}

int Shifumi::setRoundNumber(const int numberOfRounds)
{
    m_numberOfRounds = numberOfRounds;
    if(m_numberOfRounds < 1)
    {
        m_numberOfRounds = 1;
        return 0x0FF10001;
    }
    return 0;
}

std::string Shifumi::isWinner(ShifumiChoice playerChoice, int &isWon)
{
    const ShifumiChoice computerChoice = generateComputerChoice();
    std::string winner;
    isWon = 0;

    if (playerChoice == computerChoice)
    {
        isWon = 3;
        winner = "It's a tie, player and computer choose";
    }
    else if (
        (playerChoice == ShifumiChoice::Rock     && computerChoice == ShifumiChoice::Scissors) ||
        (playerChoice == ShifumiChoice::Paper    && computerChoice == ShifumiChoice::Rock)     ||
        (playerChoice == ShifumiChoice::Scissors && computerChoice == ShifumiChoice::Paper))
    {
       isWon = 1;
        winner = "Player wins";
    }
    else
    {
        isWon = 0;
        winner = "Computer wins";
    }

    return std::string("Player: ") + toString(playerChoice) + ", Computer: " + toString(computerChoice) + " → " + winner;
}

int Shifumi::createPlayer(std::string& playerName) const
{
    namespace fs = std::filesystem;
    fs::path filePath = fs::path(m_filepathPlayerJson) / "players.json";

    json playerJSON;

    std::ifstream file(filePath);
    if (file)
    {
        try {
            file >> playerJSON;
        } catch (const std::exception& e) {
            LOG(ERROR) << "Error reading JSON: " << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        LOG(WARNING) << "File players.json not found. Creating a new one." << std::endl;
        playerJSON["PlayerList"] = json::array();
    }

    // Vérifie les doublons
    if (playerJSON.contains("PlayerList") && playerJSON["PlayerList"].is_array())
    {
        for (const auto& name : playerJSON["PlayerList"])
        {
            if (name == playerName)
            {
                LOG(WARNING) << "Player already exists!" << std::endl;
                return 1;
            }
        }
    }

    if (!playerName.empty())
    {
        playerJSON["PlayerList"].push_back(playerName);

        fs::create_directories(filePath.parent_path());

        std::ofstream outFile(filePath);
        if (!outFile)
        {
            LOG(ERROR) << "Cannot write to file: " << filePath << std::endl;
            return 1;
        }

        outFile << playerJSON.dump(4);
        return 0;
    }

    return 1;
}

int Shifumi::deletePlayer(std::string& playerName) const
{
    std::filesystem::path filePath = std::filesystem::path(m_filepathPlayerJson) / "players.json";
    json playerJSON;

    std::ifstream file(filePath);
    if (!file)
    {
        LOG(ERROR) << "File players.json not found." << std::endl;
        return 1;
    }

    try {
        file >> playerJSON;
    } catch (const std::exception& e) {
        LOG(ERROR) << "Error reading JSON: " << e.what() << std::endl;
        return 1;
    }

    if (playerJSON.contains("PlayerList") && playerJSON["PlayerList"].is_array())
    {
        auto& players = playerJSON["PlayerList"];

        auto it = std::find(players.begin(), players.end(), playerName);
        if (it != players.end())
        {
            players.erase(it);
            std::ofstream outFile(filePath);
            if (!outFile)
            {
                LOG(ERROR) << "Cannot write to file: " << filePath << std::endl;
                return 1;
            }

            outFile << playerJSON.dump(4);
            return 0;
        }
        else
        {
            LOG(ERROR) << "Player not found!" << std::endl;
            return 1;
        }
    }

    LOG(ERROR) << "Invalid JSON structure: 'PlayerList' not found or not an array." << std::endl;
    return 1;
}


int Shifumi::selectPlayer(std::string& playerName)
{
    namespace fs = std::filesystem;
    fs::path filePath = fs::path(m_filepathPlayerJson) / "players.json";
    json playerJSON;

    std::ifstream file(filePath);
    if (!file)
    {
        LOG(ERROR) << "File players.json not found." << std::endl;
        return 1;
    }

    try {
        file >> playerJSON;
    } catch (const std::exception& e) {
        LOG(ERROR) << "Error reading JSON: " << e.what() << std::endl;
        return 1;
    }

    if (playerJSON.contains("PlayerList") && playerJSON["PlayerList"].is_array())
    {
        const auto& players = playerJSON["PlayerList"];

        if (players.empty())
        {
            LOG(ERROR) << "No players available." << std::endl;
            return 1;
        }

        auto it = std::find(players.begin(), players.end(), playerName);
        if (it != players.end())
        {
            m_playerSelected = playerName;
            VLOG(1) << "Player selected: " << m_playerSelected << std::endl;
            return 0;
        }
        else
        {
            LOG(ERROR) << "Player not found: " << playerName << std::endl;
            return 1;
        }
    }

    LOG(ERROR) << "Invalid JSON format: 'PlayerList' missing or not an array." << std::endl;
    return 1;
}

int Shifumi::setFilepathPlayerJson(const std::string& filepath)
{
    if(!filepath.empty())
    {
        m_filepathPlayerJson = filepath;
        return 0;
    }
    return -1;
}

std::string Shifumi::getFilepathPlayerJson()
{
    if(m_filepathPlayerJson.empty())
    {
        LOG(ERROR) << "File path for player JSON is not set." << std::endl;
        return "";
    }
    return m_filepathPlayerJson;
}

ShifumiChoice Shifumi::generateComputerChoice()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 2);
    return static_cast<ShifumiChoice>(dist(gen));
}
