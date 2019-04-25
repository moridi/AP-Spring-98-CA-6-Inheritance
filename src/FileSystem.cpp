#include "FileSystem.h"

#include <iostream>

#include "File.h"
#include "Directory.h"
#include "Link.h"

using namespace std;

void FileSystem::view(int id)
{
    try
    {
        get_element(id)->view();
    }
    catch(const std::exception& exception)
    {
        cerr << exception.what();
    }
}

void FileSystem::add_element(ElementSharedPointer new_element, int parent_id)
{
    try
    {
        check_parent_id_validity(parent_id);
        elements.push_back(new_element);
        ElementSharedPointer parent_element = get_element(parent_id);
        Directory* parent_directory = dynamic_cast<Directory*>(
                parent_element.get());
        parent_directory->add_element(new_element);
    }
    catch(const std::exception& exception)
    {
        std::cerr << exception.what();
    }
}

void FileSystem::add_directory(int id, string title, int parent_id) throw()
{
    try
    {
        check_id_validity(id);
        add_element(make_shared<Directory>(
                Directory(id, title, parent_id)), parent_id);
        Directory temp(id, title, parent_id);
    }
    catch(const std::exception& exception)
    {
        std::cerr << exception.what();
    }
}

void FileSystem::add_file(int id, std::string title,
        std::string content, int parent_id) throw()
{
    try
    {
        check_id_validity(id);
        add_element(make_shared<File>(
                File(id, title, parent_id, content)), parent_id);
    }
    catch(const std::exception& exception)
    {
        std::cerr << exception.what();
    }
}
