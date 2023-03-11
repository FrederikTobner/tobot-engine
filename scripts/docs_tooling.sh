# Generates documentation using doxyxgen (https://www.doxygen.nl/)
if [ -d "../packages/tobot_tooling/src" ]
then
    echo "Generating Documentation of the tooling ..."
    cd ../packages/tobot_tooling/src
    doxygen
    echo "Moving generated content out of the html folder ..."
    if [ -d "../docs/tobot-tooling" ]
    then
        if [ -d "../docs/tobot-tooling/html" ]
        then
            cp -avr ../docs/tobot-tooling/html/* ../docs/tobot-tooling
            echo "Removing html folder ..."
            rm -rf ../docs/tobot-tooling/html
            echo "Sucessfully generated documentation!"
        else
            echo "No html folder inside the docs foulder found"
            cd ../scripts
            exit 70
        fi
    else
        echo "No docs folder generated"
        cd ../scripts
        exit 70
    fi
else
    echo "Could not find source folder of the tobot-tooling library"
    cd ../scripts
    exit 70
fi
cd ../scripts