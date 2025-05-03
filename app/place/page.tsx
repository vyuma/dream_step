"use client";

import React, { useEffect, useState } from 'react';
import { set } from 'zod';

export default function Page() {
    const [loading, setLoading] = useState(true);

    useEffect(() => {testFunction();}, []);
    const testFunction = async () => {
        setLoading(false);
        console.log("Hello World");
    };

    return( <div>{loading}</div>)
}