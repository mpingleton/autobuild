#include "../../include/autobuild.hpp"

#include <Xml.hpp>

using namespace Autobuild;

// TODO: As work is being done on the text-parser library, this code will eventually have to be re-written.
int AutobuildRepo::readAutobuildFile()
{
    XmlDocument autobuildFile;
    autobuildFile.readFile("autobuild.xml");
    if (autobuildFile.root.element == NULL)
    {
        return -1;
    }
    else if (autobuildFile.root.element->openingTag.text != "autobuild")
    {
        return -2;
    }

    for (int rootNodeChildIndex = 0; rootNodeChildIndex < autobuildFile.root.element->children.size(); rootNodeChildIndex++)
    {
        XmlElement* currentElement = autobuildFile.root.element->children[rootNodeChildIndex].element;
        if (currentElement->openingTag.text == "target")
        {
            Target newTarget;
            for (int i = 0; i < currentElement->openingTag.attributes.size(); i++)
            {
                if (currentElement->openingTag.attributes[i].key == "platform")
                {
                    newTarget.platform = currentElement->openingTag.attributes[i].value;
                }
                else if (currentElement->openingTag.attributes[i].key == "type")
                {
                    newTarget.type = currentElement->openingTag.attributes[i].value;
                }
                else if (currentElement->openingTag.attributes[i].key == "output")
                {
                    newTarget.filenameOutput = currentElement->openingTag.attributes[i].value;
                }
            }

            for (int i = 0; i < currentElement->children.size(); i++)
            {
                XmlElement* currentTargetElement = currentElement->children[i].element;
                if (currentTargetElement->openingTag.text == "source")
                {}
                else if (currentTargetElement->openingTag.text == "sourcegroup")
                {}
            }

            targets.push_back(newTarget);
        }
        else if (currentElement->openingTag.text == "sourcegroup")
        {
            for (int i = 0; i < currentElement->children.size(); i++)
            {
                // std::cout << currentElement->children[i].element->openingTag.text << std::endl;
            }
        }
    }

    return 0;
}
