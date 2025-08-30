#include "ImagePropertyFieldGroup.h"
#include "views/business_components/sub_group/field_sub_group/ImageInfoSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/InstrumentInfoSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/GeographicInfoSubGroup.h"

ImagePropertyFieldGroup::ImagePropertyFieldGroup(QWidget *parent)
    : FieldGroup(parent)
{
    setGroupTitle("ImageProperties");
    createSubGroups();
}

ImagePropertyFieldGroup::~ImagePropertyFieldGroup()
{
    
}

void ImagePropertyFieldGroup::createSubGroups()
{
    // Create image info sub group
    ImageInfoSubGroup *imageInfoSubGroup = new ImageInfoSubGroup(this);
    m_subGroups.append(imageInfoSubGroup);
    
    // Create instrument info sub group
    InstrumentInfoSubGroup *instrumentInfoSubGroup = new InstrumentInfoSubGroup(this);
    m_subGroups.append(instrumentInfoSubGroup);
    
    // Create geographic info sub group
    GeographicInfoSubGroup *geographicInfoSubGroup = new GeographicInfoSubGroup(this);
    m_subGroups.append(geographicInfoSubGroup);
}

QList<QWidget*> ImagePropertyFieldGroup::getElements()
{
    return m_subGroups;
}