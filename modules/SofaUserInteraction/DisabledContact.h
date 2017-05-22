/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2017 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#ifndef SOFA_COMPONENT_COLLISION_DISABLEDCONTACT_H
#define SOFA_COMPONENT_COLLISION_DISABLEDCONTACT_H
#include "config.h"

#include <sofa/core/collision/Contact.h>
#include <sofa/helper/Factory.h>

namespace sofa
{

namespace component
{

namespace collision
{

template<class CM1, class CM2>
class DisabledContact : public core::collision::Contact
{
public:
    typedef CM1 CollisionModel1;
    typedef CM2 CollisionModel2;
    typedef core::collision::Intersection Intersection;
    typedef core::collision::TDetectionOutputVector<CollisionModel1, CollisionModel2> OutputVector;
protected:
    CollisionModel1* model1;
    CollisionModel2* model2;
    core::objectmodel::BaseContext* parent;
    sofa::helper::vector<core::collision::DetectionOutput*> collisions;

public:
    DisabledContact(CollisionModel1* model1, CollisionModel2* model2, Intersection* /*intersectionMethod*/)
        : model1(model1), model2(model2)
    {
    }

    void setDetectionOutputs(core::collision::DetectionOutputVector* outputs)
    {
        OutputVector* o = static_cast<OutputVector*>(outputs);
        //collisions = outputs;
        collisions.resize(o->size());
        for (unsigned int i=0; i< o->size(); ++i)
            collisions[i] = &(*o)[i];
    }

    sofa::helper::pair<core::CollisionModel*,core::CollisionModel*> getCollisionModels() { return std::make_pair(model1,model2); }

    const sofa::helper::vector<core::collision::DetectionOutput*>& getDetectionOutputs() const { return collisions; }

    void createResponse(core::objectmodel::BaseContext* /*group*/)
    {
    }

    void removeResponse()
    {
    }
};

} // namespace collision

} // namespace component

} // namespace sofa

#endif
