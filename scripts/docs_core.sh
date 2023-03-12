# Generates documentation using doxyxgen (https://www.doxygen.nl/)
if [ -d "../packages/tobot_core/src" ]
then
    echo "Generating Documentation of the core ..."
    cd ../packages/tobot_core/src
    doxygen
    echo "Moving generated content out of the html folder ..."
    if [ -d "../docs/tobot-core" ]
    then
        if [ -d "../docs/tobot-core/html" ]
        then
            cp -avr ../docs/tobot-core/html/* ../docs/tobot-core
            echo "Removing html folder ..."
            rm -rf ../docs/tobot-core/html
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
    echo "Could not find source folder of the tobot-core library"
    cd ../scripts
    exit 70
fi
cd ../scripts